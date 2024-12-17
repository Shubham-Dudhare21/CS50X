# flask is an microframework that has functions to create web application
# run "pip install flask" in terminal to install flask

# flask uses the following file arrangement
#     app.py                // main file to write the web application
#     templates/            // to put all the html files
#     requirements.txt      // list of all the external sorces to install [one per line]
#     static/               // all the static elements such as css and javascripts (html too can be included)

# to use flask(module) do the following line
from flask import Flask, render_template, request, redirect     # also has session module and jsonify module
                                                                # redirect always use "get" method to access the route

app = Flask(__name__)       # creats the app variable to use the flask functions
                            # __name__ is an python vaiable that refers to name of the file
@app.route('/')             # in bracket is the route the user will get the following function      # can send to route from html-form with [  action="/"  ]
def function_name():        # this function will run if the user goes to "/(default)" path of the web app
    return 'hello world!'

@app.route('/greet_get')        # this route('/route')  will by default will only use get method
def greet_get():
    name = request.args.get("key_name")     # request.args has get function to recive the keyvalue pair from the url
                                            # key_name is a key of an user input data from the form in html, present in url
    return render_template('greet.html', placeholder_name=name)    # render_template() function shows the html page from the templates folder
                                                                   # placeholder_name is an html element --> {{ placeholder_name }}
# to use the post method define the route as following
@app.route('/greet_post', methods=["POST"])     # can also create an comma-separeted list for methods as --> ["GET", "POST"]
def greet_post():
    name = request.form.get("key_name")         # request.form can get the data from the form(even with post method). without relaying on the url
    return render_template('greet.html', placeholder_name=name)
# you can also use the get and post methods together and insted of creating different route for simple functionalities use if else to return the template as:
    # @app.route('/', methods=["GET", "POST"])
    # def greet():
    #     if request.methods == "POST":        # this will check if the method is post or not  methods is an list in request that stores the method for the currently loding page
    #         name = request.form.get("key_name")
    #         return render_template('greet.html', placeholder_name=name)
    #     return render_template('form.html')




# the following is the method to run the flask app if the app is not running by default
# if __name__ = "__main__":
#     app.run(debug=True)


# ------------------------------------------------------------------------------------------------------------------------------------------------------------------#
# ----------------------------------------------- the following notes are for the html -----------------------------------------------------------------------------#

# in html file use {{ placeholder_name }} to repalce with data from the .py file
# in html use the following to setup the layout template and use it in the other html files
    # {% block body %} {% endblock %}    --> in the parent file where you want the data from other file to go
    # {% extends 'filename.html' %}   {% block body %} "write the html here" {% endblock %}     --> in the child file


# in html form there are methods to send the data such as get and post:
    # GET: Sends data via the URL. It's typically used for retrieving data. The data is visible in the URL, which can be bookmarked or cached.
    # POST: Sends data in the body of the request. It's used for submitting data, such as form submissions. The data is not visible in the URL, making it more secure for sensitive information.
    # there are methods such as delete and put but they are not that well supported in the world of browser

# if no value is submitted as input in the form you can use the default text at place of value as follows [in html file]
    # original code:
        # hello, {{ placeholder }}
    # Jinja code for if the placeholder value is empty or null
        # hello, {% if placeholder %} {{placeholder}} {% else %}Default value{% endif %}

# to create an dropdown menu in html do the following
    # <select name="dropdown">
    #     <option disabled selected value=""> Select </option>
    #     <option> option 1 </option>
    #     <option> option 1 </option>
    #     <option> option 1 </option>
    # </select>
# to create radio buttons or checkboxes
    # <input name="whatever_name" type="radio" value="anything"> option 1    // to get checkboxes change radio to checkbox
    # if we use checkbox do the following in app.py to validate input:
    #     for sport in request.form.getlist("sports"):
    #         if sport not in SPORTS:
    #             return "failure"


# FOR LOOP IN JINJA (HTML)
    # {% for element in list %}     // in place of list you can use dictionary or any thing
    #     {{element}}               // to access the key in dict just use {{ element }} and for value {{ dictionary_name[element] }}
                                  # // if you use list of dictionaries you can use element.name_key and element.value_key
    # {% endfor %}



# use sql modules to store the web apps data to database


# -------------------------------------------------------------------------------------------------------------------------------#
# MVC model
    # V - view - what the user sees --> templates in the web app
    # C - Controller - this is the logic behind the web app --> app.py file
    # M - Model - this is the database to store the data --> anything.db file


# --------------------------------------------------------------------------------------------------------------------------------------------------------- #
# --------------------------------------------------------------- COKIES AND SESSIONS --------------------------------------------------------------------- #
# this is useful for the websites to remember the user and not to repeatedly ask for login until the expiry oft the cookie
# cokies is set for an user after first login as
    # Set-Cookie:   session=value
# after the cookie is set, the web request from user will contain
    # Cookie:   session=value
# Cookie is an big alpha-numeric number that is unique identifier. it also does not need to contain username or password in any way

# this can be used in flask with session module as:
    # from flask import session
    # from flask_seeion import Session

    # app = Flask(__name__)
    # app.config["SESSION_PERMANENT"] = False       // to delete the cookie after closing the browsser
    # app.config["SESSION_TYPE"] = "filesystem"     // to store the data in session(e.g. cart) to filesystem insted of on the cookie itself
    # Session(app)                                  // activates Sessions on the app

    # the session in flask is an dictionary with key and values columns
        # to store the data to session dict
            # session["key_name"] = data    e.g.    session["name"] = request.form.get("name")  // this recives the value for name key from form and saves it in session["name"]
        # to recive the data back
            # var_name = session.get("key_name")    var_name can be html_id_name
        # to delete data from session with a certain key
            # del session["key_name"]
        # to clear the session at once
            # session.clear()
    # Use sessions for functionalities such as cart and database for data such as products in the store
        # e.g. create an session with "cart" key and make it an empty list and then append the products id to cart as:
            # if "cart" not in session:
            #     session["cart"] = []
            # session["cart"].append(new_value_to_append)




# -------------------------------------------------------------------------------------------------------------------------------------------------------------- #
# AJAX stands for Asynchronous JavaScript and XML.
# AJAX allows web pages to be updated asynchronously by exchanging small amounts of data with the server behind the scenes.
# This means that parts of a web page can be updated without reloading the entire page.

# e.g. using search in the shows for updating the html without submitting the form
    # <input autocomplete="off" autofocus type="search" placeholder="Query" name="q">
    # <ul></ul>
    # <script>
    #     let input = document.querySelector('input');
    #     input.addEventListner('input', async function(){                # to update the result with data input use - async {similar to mouse events or key up}
    #         let response = await fetch('/serch?q=' + input.value)       # await fetch('route?key=' + value)     --> this will pass the current values to the route by get method
    #                                                                         # and store the returned data of the route in the response variable
    #         let shows = await response.text();                  # the shows variable only stores the response.text()    i.e. result of the /search route if the query was submitted
    #         document.querySelector('ul').innerHTML = shows;     # puts the shows data inside the "ul" element
    #     });
    # </script>



# -------------------------------------------------------------------------------------------------------------------------------------------------------------- #
# API - Application Programming Interface
# this is someone eles's server or service from where we can get the data from, for our application.

# nowadays we dont get data from the HTML OR XML but by JSON which is JavaScript Object Notation
# JSON is an large list of dictionaries which is not as messy as html but clean and machine readable
# only double qoutes are allowed for strings and char
# example:
    # [
    #     {"name": "Alice", "age": 30},
    #     {"name": "Bob", "age": 25},
    #     {"name": "Charlie", "age": 35}
    # ]
# this can be iterated over by for each loop, and for each dict in list to access the value can access as:
    # for dict in list:
    #     {{ dict["name"] }}
    #     {{ dict["age"] }}

# to use JSON in the flask do the following
    # from flask import jsonify
    # .
    # .
    # .

    # @app.route("/search")
    # def search():
    #     q = request.args.get("q")
    #     if q:
    #         shows = db.execute("SELECT * FROM shows WHERE title LIKE ? LIMIT 50", "%" + q + "%")
    #     else:
    #         shows = []
    #     return jsonify(shows)
