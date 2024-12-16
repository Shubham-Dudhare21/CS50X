document.querySelector('#nav_enter').addEventListener('click', function(event) {
    let name = document.querySelector("#hello").value;
    if (name == ''){
        document.getElementById("hiname").innerText = 'HELLO USER';
        document.getElementById("subtitle").innerText = 'THIS IS CS50';
        document.querySelector('#instruct').innerText = 'Use Links in Navbar';
        document.querySelector("body").style.backgroundColor = '#FDF5DF';
        event.preventDefault();
    } else{
        document.getElementById("hiname").innerText = 'HELLO ' + name.toUpperCase();
        document.getElementById("subtitle").innerText = 'THIS IS CS50';
        document.getElementById("hiname").style.fontSize = '5rem';
        document.querySelector("body").style.backgroundColor = '#C2EDCE';
        document.querySelector('#instruct').innerText = 'Use Links in Navbar';
        event.preventDefault();
    }
});

