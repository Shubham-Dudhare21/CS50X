//answers: 'I am the master of the universe!' 'debugging'
document.addEventListener('DOMContentLoaded', function() {
    let mcqans = document.querySelector('.mcqans');
    mcqans.addEventListener('click', function() {
        mcqans.style.backgroundColor = 'green';
        document.getElementById('result').innerHTML = "CORRECT";
    });

    let mcq = document.getElementsByClassName('mcq');
    for (let i = 0; i < mcq.length; i++){
        mcq[i].addEventListener('click', function(){
            mcq[i].style.backgroundColor = 'red';
            document.getElementById('result').innerHTML = "INCORRECT";
        })
    }

    document.getElementById('enter').addEventListener('click', function() {
        let answer = document.getElementsByTagName('input')[0].value;
        if(answer.toLowerCase() == 'debugging'){
            document.getElementsByTagName('input')[0].style.backgroundColor = 'green';
            document.getElementById('result_').innerHTML = "CORRECT";
        } else {
            document.getElementsByTagName('input')[0].style.backgroundColor = 'red';
            document.getElementById('result_').innerHTML = "INCORRECT";
        }
    });
});
