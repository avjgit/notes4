window.onload = mainFunction;

function getInputs(id, tag){
    tag = typeof tag !== 'undefined' ? tag : "input"; // default tag - input
    return document.getElementById(id).getElementsByTagName(tag);
}

function are_valid_temperatures(temperatures){
    var i;
    var min_temperature = -50;
    var max_tempearture = +50;
    for(i = 0; i < temperatures.length; i++){

        if (temperatures[i].value === 'undefined' ||
           temperatures[i].value === '') {
            alert("temperatures should be provided!");
            return false;
        }
        if (isNaN(temperatures[i].value)) {
            alert("temperatures should be a number!");
            return false;
        }
        if (temperatures[i].value < min_temperature ||
           temperatures[i].value > max_tempearture) {
            alert("temperatures should be from "
                + min_temperature + " to "
                + max_tempearture + " degC!"
            );
            return false;
        }
    }
    return true;
}

function are_valid_windspeeds(windspeeds){
    var i;
    for(i = 0; i < windspeeds.length; i++){

        if (windspeeds[i].value === 'undefined' ||
           windspeeds[i].value === '') {
            // lets set default for wind
           windspeeds[i] = 0;
        }
        if (isNaN(windspeeds[i].value)) {
            alert("windspeed should be a number!");
            return false;
        }
        if (windspeeds[i].value < 0) {
            alert("windspeed should be non-negative!");
            return false;
        }
    }
    return true;
}

function are_valid_clouds(sunclouds){
    var i;
    for(i = 0; i < sunclouds.length; i++){
        if (sunclouds[i].selectedIndex === 0) {
            alert("clouds should be specified!");
            return false;
        }
    }
    return true;
}

function mainFunction(){
    document.getElementById("drawbutton").onclick = function(){

        var temperatures = getInputs("temperatures");
        var windspeeds   = getInputs("windspeed");
        var sunclouds    = getInputs("sunclouds", "select");

        if (
            are_valid_temperatures(temperatures) &&
            are_valid_windspeeds(windspeeds) &&
            are_valid_clouds(sunclouds)
        ){
            draw_graph();
        }
    };
}

function drawGraph(label,value){
    var nv=[]; //normalized value
    var max=value[1];
    for(var i=2; i<6; i++){
            max=Math.max(max,value[i]);
    }
    var highest=280;
    for(var i=1; i<6; i++)
        nv[i]=(highest/max)*value[i];

    var canvas = document.getElementById("graph");
    if (canvas.getContext){
      var ctx = canvas.getContext('2d');
      ctx.clearRect(0,0,canvas.width,canvas.height);
      ctx.fillStyle="#FCA";
      ctx.fillRect(20,300,560,2);
      for(var i=1; i<6; i++){
          ctx.fillStyle="lightgrey";
          ctx.fillRect(60+100*(i-1),300-nv[i],80, nv[i]);
          ctx.fillStyle="grey";
          ctx.fillText(label[i],60+100*(i-1),350);
      }
    }
};