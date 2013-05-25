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

        var i;
        for(i = 0; i < temperatures.length; i++){
            alert(temperatures[i].value);

            if (temperatures[i].value == 'undefined' ||
               temperatures[i].value === '') {
                alert("t should be provided!");
            }
            if (isNaN(temperatures[i].value)) {
                alert("t should be a number!");
            }
            if (temperatures[i].value < -50 ||
               temperatures[i].value > 50) {
                alert("t should be from -50 to 50 degC!");
            }
        }

        for(i = 0; i < windspeeds.length; i++){

            if (windspeeds[i].value == 'undefined' ||
               windspeeds[i].value === '') {
                // lets set default for wind
               windspeeds[i] = 0;
            }
            if (isNaN(windspeeds[i].value)) {
                alert("ws should be a number!");
            }
            if (windspeeds[i].value < 0) {
                alert("ws should be non-negative!");
            }
        }

         for(i = 0; i < sunclouds.length; i++){
            if (sunclouds[i].selectedIndex === 0) {
                alert("cl should be specified!");
            }
        }
    };
}