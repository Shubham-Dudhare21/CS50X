// ECMAscript is the standard to update the javascript so all the browsers in the world can standerdise the support of JS.
// if you have learned the ECMAscript version6 then you dont have to worry about the JS for future updates
// all the updates have same structure for programming as version 6

// always use function(event){ event.preventDefault();} --> to not refresh the page after completing the function in event listner

// 1. ways to print in js
    // console.log("Hello, World!");
    // alert("this is alert");
    // document.write("this is the document write");

// 2. JS console log API
    // console.log("Hello, World!", 1+1, "<-- this is math");
    // console.error("this is error!");
    // console.warn("this is warning");

// 3. JS variables
// to get the type of any variable in JS
    // typeof var_name;
// always use let
    // let a = 10;
// let creates the temporary variable for the block of code only
// this creats an variable named a with value 10
    // var b = 20;
// the above creates the variable called b with value 20
    // const c = 30;
// cant change the constant var once declared

// 4. Data types
// supports int, float, strings, booleans, array and objects
// objects is an key value pair data type like dictionary
    // var obj = {
    //      key1:10,
    //      key2:20
    //      };
// array are defined as:
    // var arr = [1, 2, 3, 4, 5];
    // to get the value of the array element
    // arr[0]
// JS also has undefined or null data type
// following is the ways to declare the undefined variable
    // var a = undefined;
    // var a; // this is also undefined
// null variable
    // var b = null;

// 5. Operators in JS
// JS supports arithematic opperators + , - , * , /
// assignment operators   =
// comparison operators  >= , > , <= , < , ==
// logical operators  || ! &&


// 6. Functions in JS
    // function name(parameter){
    //     ---
    //     ---
    // }

// 7. Conditions in JS
// if statements / else if statement / if else statement
    // if (a < b){
    //     console.log("a is less than b");
    // }else if (a > b){
    //     console.log("b is less than a");
    // }
    // else{
    //     console.log("a is equal to b");
    // }

// 8. LOOPS
// for loop
    // for (var i = 0; i < 10; i++){
    //     console.log("line ", i);
    // }
// for each
    // arrayname.forEach(function(element){
    //     console.log(element);
    // });
// while loop
    // a = 0
    // while(a < 10){
    //     console.log("line ", a);
    //     a++;
    // }
// do while
    // do{
    //     console.log("line ", a);
    //     a++;
    // }while (a < 0);
// has break for exiting the loop
// has continue for skiping the stage and continue the iterition

// 9. Array methods
// let arr = ["fan", 20, 1.501, null, true];
// array length --> arr.length;
// removing last element of array --> arr.pop();
// adding element to array at end --> arr.push("new value");
// first element gets removed from array --> arr.shift();
// add new element at start of array --> arr.unshift("new value");
// converts all elements of array to string (as in csv file) --> arr.toString();
// sorts the array --> arr.sort();


// 10. String methods in JS
    // let str = "Hello, World! this is JS World";
    // str.lenght   --> length of the string
    // str.indexOf("World");    --> gives the index of the first leltter of the parameter i.e. W, where the whole parameter is appearing for the first time => 7
    // str.lastindexOf("World");    --> gives the index of the last occurence of the world in str (index of the W's position)
    // str.slice(0, 3); --> returns the string from index 0 to 3 (excluding 3) i.e. 'Hel'
    // str.replace("World", "Earth")    --> replaces the first occurence of the the first parameter with second parameter

// 11. Dates in JS
    // let var = new Date();
// new keyword is used to create new dates and Date() returns the current time and date
    // returns the date and time with time zone
    // var.getTime();   -->returns time
    // var.getFullYear();    --> returns year
    // var.getDay();    --> returns the day index for array starting from sunday to saturday

// 12. DOM(Document Object Model) Manipulation
// document keyword is used to access the html data
// used to manipulate the html and css page
    // let new = document.getElementById('Id');   --> the ID can be Id or Tag or Class and Element can be Idname or classname
// new variable has all the data of the specified tag or class in the html
    // let elemClass = document.getElementsByClassName('classname') --> Returns the collection of the Elements(innerHTML) containing the classname.
    // document.getElementsByClassName('classname')[0].style.backgroundColor = "red"     -->to chamge the style(css) of the first occurence of the class
// can also do the same thing with
    // elemClass[0].style.backgroundColor = "red";
// to add or remove the class from the classes on the html tag
    // elemClass[0].classList.add("classname2");
    // elemClass[0].classList.remove("classname");
// to access HTML inside the tags (including text and other tags)
    // elemClass[0].innerHTML;
// to access only text inside the tags and not other tags
    // elemClass[0].innerText;
// to add to the inner HTML Element or inner Text Use the following
    // let newElem = document.createElement('tagname')  --> use the tag you want to create in place of tagename e.g. p /div /li etc.
    // newElem.innerText = "put your text here";    --> adds the string text to the innerText or innerHTML of the the newElem
    // elemClass[0].appendChild(newElem);   --> .appendChild() appends the whole newElem data to the tag within elemClass at 0 index
// suppose there is an variable created named newElem and you want to replace it with the previously added oldElem
    // elemClass[0].replaceChild(newElem, oldElem);    --> this finds where the data from the oldElem is in the document and replaces it with the newElem
// you can also write the data as a string in the above instead of the vaiable parameters {or} use document.querySelector {or} document.getElementBy__();
// you can also remove the data from the dacument by following
    // elemClass[0].removeChild(newElem);
// there are few common dom functions as follows. functions returns the data that functionname suggests
    // document.scripts
    // document.location
    // doucment.URL
    // document.title
    // document.links
    // document.images
    // document.domain
// Query selector returns the data specified (use . for class, # for id, and only tagname if want to get tag data)
    // let qs = document.querySelector('.classname')    --> returns the data of only the first instance of the classname
    // let qsa = document.querySelectorAll('.classname')    --> returns an list(array) with data of every occurence of classname as an element of the list
// to get the input from the html form use
    // document.querySelector('#id').value;

// 13. EVENTS in JavaScript
// events are the functionality that can be attached to the html tag so we can define what the JS do when the event is triggered
// can use the events from html as follows in button tag
    // <button class="" onclick="functionname()"></button>  --> onclick="" calls the function when the button is clicked (this needs the js function at end of html or used with 'DOMContentLoaded')
    // function functionname() {code to be executed}
// to execute the function only after the document is loaded you can use the following
    // window.onload = function(){  code    };
// to use the whole thing in JS you can use addEventListener('event', function() {code to be executed});    --> canbe used on any tags
    // document.querySelectorAll('.classname').addEventListner('click', function() {-----------});
// the events are of following types
    // mouseover
    // click
    // mouseout
    // mouseup
    // keyup
    // keydown
    // mousedown


// 14. SetTimeout and setintervals
// timeout is used set timer for the function to be called     --> can be used with event listner or for loading of the page
    // setTimeout(functionname, 1000);  --> function must be declared earlier and time is in millsec so 1000 = 1sec
// setInterval is used to repeat some function after the set time in loop   --> example blinking text
    // function blink(){
    //     if (visible){text = invisible}
    //     else{visible}
    // }
    // setInterval(blink, 500); --> time in millisec    --> gives infinite loop of the functions
// to limit the setinterval by the events use the following
    // clr = setInterval(function, time)    --> setinterval returns the id that is stored in clt variable
    // clearInterval(clr);  --> stops the setInterval with the id strored in the 'clr'
// similarly clearTimeout(id_variable) is used to stop the setTimeout before it activates


// 15. Local Storage in JS
// helps to store the data localy on the user device
// this stores only data that is either loaded to user device by the use of JS or user inputed data that is stored localy
// you need to code in JS to store(specified) data in local storage
    // localStorage --> returns the data stored localy for the domain
    // localStorage.clear() -->clears the local storage
    // localStorage.setItem('key', 'value');    --> stores the data as key:'value' in the local storage
    // localStorage.getItem('key');    --> returns(read) the data associated with the key
    // localStorage.removeItem('key');  --> removes the data for the key and the key itself
// its important to note that "Never store the imp. or sencitive data on local storage"
// the local storage is not secure and any one can access the data from browser's console


// JSON - JavaScript Object Notation
// file format i.e. used to exchange the data (easy to transport and safe)
    // obj = {name: 'shubham', length:1}   // create an object with name obj
    // jso = JSON.stringify(obj);  // converts the obj data into JSON string
// the string can be transported easily now
// JSON only supports double qoutes of is the object contains double qoute JSON uses escape sentence(\) before that qoute
    //obj = {'name':'ab"c'}; --> this converts to --> {"name":"ab\"c"}
// to convert the valid JSON string into object again use following
    //parsed = JSON.parse('{"name":"abc"}');    // use valid JSON string as input or
    //parsed = JSON.parse(jso); // previously created jso string using stringify()

// ECMAscript 6 added the template Literals to use the variables direclty in the string with $
    // a = 'Shubham!';
    // console.log('this is $(a)'); --> prints to console   --> this is Shubham!








// DOM (Document Object Model) in JS (by cs50)
// document is refering to the html page (all the tags with their curusponding innerHTML)
getElementBy
