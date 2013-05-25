window.onload = mainFunction;

function getInputs(id, tag){
    tag = typeof tag !== 'undefined' ? tag : "input"; // default tag - input
    return document.getElementById(id).getElementsByTagName(tag);
}

function validate_temperatures(temperatures){
    var i;
    var min_temperature = -50;
    var max_tempearture = +50;
    for(i = 0; i < temperatures.length; i++){
        alert(temperatures[i].value);

        if (temperatures[i].value === 'undefined' ||
           temperatures[i].value === '') {
            alert("temperatures should be provided!");
        }
        if (isNaN(temperatures[i].value)) {
            alert("temperatures should be a number!");
        }
        if (temperatures[i].value < min_temperature ||
           temperatures[i].value > max_tempearture) {
            alert("temperatures should be from "
                + min_temperature + " to "
                + max_tempearture + " degC!"
            );
        }
    }
}

function validate_windspeeds(windspeeds){
    var i;
    for(i = 0; i < windspeeds.length; i++){

        if (windspeeds[i].value === 'undefined' ||
           windspeeds[i].value === '') {
            // lets set default for wind
           windspeeds[i] = 0;
        }
        if (isNaN(windspeeds[i].value)) {
            alert("windspeed should be a number!");
        }
        if (windspeeds[i].value < 0) {
            alert("windspeed should be non-negative!");
        }
    }
}

function validate_clouds(sunclouds){
    var i;
    for(i = 0; i < sunclouds.length; i++){
        if (sunclouds[i].selectedIndex === 0) {
            alert("clouds should be specified!");
        }
    }
}

function mainFunction(){
    document.getElementById("drawbutton").onclick = function(){

        var temperatures = getInputs("temperatures");
        var windspeeds   = getInputs("windspeed");
        var sunclouds    = getInputs("sunclouds", "select");

        validate_temperatures(temperatures);
        validate_windspeeds(windspeeds);
        validate_clouds(sunclouds);

    };
}