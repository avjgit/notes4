window.onload = mainFunction;

function getInputs(id, tag){
    tag = typeof tag !== 'undefined' ? tag : "input";
    return document.getElementById(id).getElementsByTagName(tag);
}

function mainFunction(){
    document.getElementById("drawbutton").onclick = function(){

        var temperatures = getInputs("temperatures");
        var windspeeds   = getInputs("windspeed");
        var sunclouds    = getInputs("sunclouds", "select");

        alert(temperatures[0].value);
        alert(windspeeds[0].value);
        alert(sunclouds[0].selectedIndex);

    }
}