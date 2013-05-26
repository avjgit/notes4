window.onload = mainFunction;

function getInputs(id, tag){
    tag = typeof tag === 'undefined' ? "input" : tag; // default tag - input
    var inputs = document.getElementById(id).getElementsByTagName(tag);
    var i;
    var values = [];
    for (i = 0; i < inputs.length; i++){
        values[i] = inputs[i].value;
    }
    return values;
}

function getLabelsInputs(id, tag){
    tag = typeof tag !== 'undefined' ? tag : "input"; // default tag - input
    var inputs = document.getElementById(id).getElementsByTagName(tag);
    var i;
    var values = [];
    for (i = 0; i < inputs.length; i++){
        values[i] = inputs[i].value;
    }
    return values;
}

function are_valid_temperatures(temperatures){
    var i;
    var min_temperature = -50;
    var max_tempearture = +50;
    for(i = 0; i < temperatures.length; i++){

        if (temperatures[i] === 'undefined' ||
           temperatures[i] === '') {
            alert("temperatures should be provided!");
            return false;
        }
        if (isNaN(temperatures[i])) {
            alert("temperatures should be a number!");
            return false;
        }
        if (temperatures[i] < min_temperature ||
           temperatures[i] > max_tempearture) {
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

        if (windspeeds[i] === 'undefined' ||
           windspeeds[i] === '') {
            // lets set default for wind
           windspeeds[i] = 0;
        }
        if (isNaN(windspeeds[i])) {
            alert("windspeed should be a number!");
            return false;
        }
        if (windspeeds[i] < 0) {
            alert("windspeed should be non-negative!");
            return false;
        }
    }
    return true;
}

function are_valid_clouds(sunclouds){
    var i;
    for(i = 0; i < sunclouds.length; i++){
        if (sunclouds[i] === "") {
            alert("clouds should be specified!");
            return false;
        }
    }
    return true;
}

function mainFunction(){
    document.getElementById("drawbutton").onclick = function(){

        var labels       = ["Day 1", "Day 2", "Day 3", "Day 4", "Day 5"];
        var temperatures = getInputs("temperatures");
        var windspeeds   = getInputs("windspeed");
        var sunclouds    = getInputs("sunclouds", "select");

        if (
            are_valid_temperatures(temperatures) &&
            are_valid_windspeeds(windspeeds) &&
            are_valid_clouds(sunclouds)
        ){
            drawGraph(
                labels,
                temperatures,
                windspeeds,
                sunclouds
            );
        }
    };
}

function drawGraph(label,value){
    var canvas = document.getElementById("graph");
    var cwidth = canvas.width;
    var cheight = canvas.height;

    if (canvas.getContext){
        var ctx = canvas.getContext('2d');
        ctx.clearRect(0,0,cwidth,cheight);

        var labels_width        = Math.floor(cwidth * .1);
        var temp_bars_width     = Math.floor(cwidth * .3);
        var temp_color_width    = Math.floor(cwidth * .2);
        var wind_width          = Math.floor(cwidth * .2);
        var cloud_width         = Math.floor(cwidth * .2);

        // create line
        var line = {
            color: "blue",
            width: Math.floor(cwidth * 0.9),
            height: 2
        };

        ctx.fillStyle = line.color;
        ctx.fillRect(20,300,line.width,line.height);

        for(var i=0; i<5; i++){
            ctx.fillStyle="grey";
            ctx.fillText(label[i],60+100*(i),30);
        }

        var nv=[]; //normalized value
        var max=value[0];
        for(var i=1; i<5; i++){
            max=Math.max(max,value[i]);
        }
        var highest=280;
        for(var i=0; i<5; i++)
            nv[i]=(highest/max)*value[i];

        for(var i=0; i<5; i++){
            ctx.fillStyle="lightgrey";
            ctx.fillRect(60+100*(i),300-nv[i],80, nv[i]);
        }
    }
};