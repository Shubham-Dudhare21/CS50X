from flask import Flask, render_template, request, redirect
from cs50 import SQL

app = Flask(__name__)

SPORTS = ["Football", "Basketball", "Soccer"]
# STUDENTS = {}     // if the dict is used to store data

# the following is command to access the database
db = SQL("sqlite:///registration.db")

@app.route('/')
def index():
    return render_template("index.html", sports=SPORTS)

@app.route('/register', methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name:
        return render_template("error.html", message="enter your NAME")
    if not sport:
        return render_template("error.html", message="Enter the Sport")
    elif sport not in SPORTS:
        return render_template("error.html", message="Enter from the given sports")
    # STUDENTS[name] = sport    # if you use the dict inside the app to store data  // which is bad practice
    # the following is adding the data to database
    db.execute("INSERT INTO students (name, sport) VALUES(?, ?);", name, sport)
    return redirect("/registrants")

@app.route('/registrants')
def registrants():
    STUDENTS = db.execute("SELECT * FROM students;")
    return render_template("registrants.html", students=STUDENTS, sucess_placeholder="Congrats! You Are Registered!", color_placeholder="green")

@app.route('/deregister', methods=["POST"])
def deregister():
    id = request.form.get("id")
    db.execute("DELETE FROM students WHERE id IS ?;", id)
    STUDENTS = db.execute("SELECT * FROM students")
    return render_template("registrants.html", students=STUDENTS, sucess_placeholder="You Are Deregistered!", color_placeholder="black")
