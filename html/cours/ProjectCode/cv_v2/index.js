const { keypress } = require("./lib/keypress");
var listener = new window.keypress.Listener();

function show() {
    var element = document.getElementById("showcase");
    var poutre = document.getElementById("blur");
    var neonname = document.getElementById("myname");
    var start = document.getElementById("starting");
    var pac = document.getElementById("pac");

    element.classList.toggle("active");
    poutre.classList.toggle("active");
    neonname.classList.toggle("active");

    start.classList.remove("phase2");
    pac.classList.remove("phase2");

}

function start() {
    var start = document.getElementById("starting");
    var pac = document.getElementById("pac");

    start.classList.add("phase2");
    pac.classList.add("phase2");
}

function contactoff() {
    var contshow = document.getElementById("contoff");

    contshow.classList.toggle("on");
    
    setTimeout(hideoff, 200);

}

function hideoff() {
    var butoff = document.getElementById("off");
    var onleft = document.getElementById("onleft");
    var onright = document.getElementById("onright");


    if (onleft.classList.contains("onright")){
        onleft.classList.remove("onright")
        onright.classList.add("onleft")
    }   else {
        onleft.classList.add("onright")
        onright.classList.remove("onleft")
    }

    if  (butoff.classList.contains("on")) {
        butoff.classList.remove("on");
    } else {
        butoff.classList.add("on");
    }

}
