import os

from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    id = session.get("user_id")
    if not id:
        return redirect("/login")
    user = db.execute("SELECT * From users WHERE id IS ?", id)

    transaction_data = {}
    transactions = db.execute("SELECT * FROM transactions WHERE user_id = ?", id)
    for transaction in transactions:
        if transaction["stock_symbol"] in transaction_data.keys():
            if transaction["transaction_type"] == "bought":
                transaction_data[transaction["stock_symbol"]] += transaction["share_numbers"]
            else:
                transaction_data[transaction["stock_symbol"]] -= transaction["share_numbers"]
        else:
            transaction_data[transaction["stock_symbol"]] = transaction["share_numbers"]

    stock_data = []
    total_stocks_value = 0
    for key in transaction_data.keys():
        stock = lookup(key)
        company = db.execute("SELECT * FROM companies WHERE stock_symbol = ?", key)
        dict = {"symbol": key, "shares": transaction_data[key],
                "company_name": company[0]["company_name"], "current_price": stock["price"]}
        stock_data.append(dict)
        total_stocks_value += (transaction_data[key] * stock["price"])

    return render_template("index.html", username=user[0]["username"], cash=usd(user[0]["cash"]), stock_data=stock_data, total_value=usd(user[0]["cash"] + total_stocks_value), total_stocks_value=total_stocks_value, usd=usd)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        number = request.form.get("shares")

        stock_data = lookup(symbol)

        if stock_data == None:
            return apology("Enter valid symbol")

        try:
            number = int(number)
        except ValueError:
            return apology("Enter valid number of stocks")

        if number <= 0:
            return apology("Enter positive value")

        user = db.execute("SELECT * FROM users WHERE id IS ?", session.get("user_id"))

        if user[0]["cash"] < (number * stock_data["price"]):
            return apology("You do not have enough balance")

        current_time = datetime.now()
        db.execute("INSERT INTO transactions(user_id, stock_symbol, price, share_numbers, transaction_type, transaction_time) VALUES(?, ?, ?, ?, 'bought', ?)",
                   user[0]["id"], stock_data["symbol"], stock_data["price"], number, current_time)

        if len(db.execute("SELECT * FROM companies Where stock_symbol = ?", stock_data["symbol"])) == 0:
            (db.execute("INSERT INTO companies(stock_symbol, company_name) VALUES(?, ?)",
                        stock_data["symbol"], stock_data["name"]))

        db.execute("UPDATE users SET cash = ? WHERE id IS ?",
                   (user[0]["cash"] - (stock_data["price"]) * number), user[0]["id"])

        return redirect("/")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session.get("user_id")
    history = db.execute(
        "SELECT * FROM transactions WHERE user_id = ? ORDER BY transaction_time DESC", user_id)
    return render_template("history.html", history=history, usd=usd, lookup=lookup)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        quote_search = request.form.get("symbol")
        if not quote_search:
            return apology("Enter a quote search!")

        quotes = lookup(quote_search)
        if not quotes:
            return apology("Enter proper quote search!")

        return render_template("quote.html", quotes=quotes)

    return render_template("quote.html", quotes={"name": "Company Name", "price": 0, "symbol": "CPNM"})


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        password_confirm = request.form.get("confirmation")
        if not username or not password:
            return apology("enter USERNAME and PASSWORD")

        if not (password == password_confirm):
            return apology("CONFIRM PASSWORD")

        if "--" in username or "--" in password:
            return apology("repitition of symbol in row not allowed")

        username_check = db.execute("SELECT username FROM users WHERE username IS ?", username)
        if len(username_check) > 0:
            return apology("USERNAME Already Taken.")

        password = generate_password_hash(password)

        db.execute("INSERT INTO users(username, hash) VALUES(?, ?)", username, password)
        return redirect("/")
    else:
        return render_template("registration.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user_id = session.get("user_id")
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        number = int(request.form.get("shares"))

        if not symbol or not number:
            return apology("Enter Both fields properly")

        # the following dict stores {stock_symbol:number of shares} as {"NFLX":4, ...}
        transaction_data = {}
        transactions = db.execute("SELECT * FROM transactions WHERE user_id = ?", user_id)
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        stock = lookup(symbol)

        if stock == None:
            return apology("Enter Proper Stock Symbol")

        for transaction in transactions:
            if transaction["stock_symbol"] in transaction_data.keys():
                if transaction["transaction_type"] == "bought":
                    transaction_data[transaction["stock_symbol"]] += transaction["share_numbers"]
                else:
                    transaction_data[transaction["stock_symbol"]] -= transaction["share_numbers"]
            else:
                transaction_data[transaction["stock_symbol"]] = transaction["share_numbers"]

        if transaction_data[symbol] < number:
            return apology("you do not have enough share numbers")
        if 0 > number:
            return apology("don't enter negative numbers")

        current_time = datetime.now()
        db.execute("INSERT INTO transactions(user_id, stock_symbol, price, share_numbers, transaction_type, transaction_time) VALUES(?, ?, ?, ?, 'sold', ?)",
                   user_id, symbol, stock["price"], number, current_time)
        user_cash += (number * stock["price"])
        db.execute("UPDATE users SET cash = ? WHERE id = ?", user_cash, user_id)

        return redirect("/")

    symbols = db.execute(
        "SELECT DISTINCT stock_symbol FROM transactions WHERE user_id = ?", user_id)
    return render_template("sell.html", symbols=symbols)
