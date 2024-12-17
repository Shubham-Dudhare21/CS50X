from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def greet_form():
    if request.method == "POST":
        name = request.form.get("name")
        if name == "":
            return render_template("greet.html", warning_ph="Please Enter Name.")
        return render_template("greet.html", name_placeholder=name.capitalize())
    return render_template("greet_form_post.html")
