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
                    sunclouds);
            }
        };
    }

    function normalize_values(values, max)
    {

    }

    function drawGraph(label,temperatures){
        var canvas = document.getElementById("graph");
        var cwidth = canvas.width;
        var cheight = canvas.height;

        if (canvas.getContext){
            var ctx = canvas.getContext('2d');
            ctx.clearRect(0,0,cwidth,cheight);

            var draw_margin = Math.floor(cwidth * .1);
            var draw_area = cwidth - 2*draw_margin;

            var labels_height       = Math.floor(cheight * .05);
            var chart_height        = Math.floor(cheight * .35);
            var chart_half          = Math.floor(chart_height/2);

            var color_height        = Math.floor(cheight * .2);
            var wind_height         = Math.floor(cheight * .2);
            var cloud_height        = Math.floor(cheight * .2);

            var labels_start        = labels_height;
            var chart_start         = labels_start + chart_height;
            var color_start         = chart_start + color_height;
            var wind_start          = color_start + wind_height;
            var cloud_start         = wind_start + cloud_height;

            // create chart X axis
            var line = {
                color: "blue",
                width: draw_area,
                height: 2,
                start_x: draw_margin,
                start_y: labels_height + chart_half
            };

            var highest = Math.floor(chart_half * .9);

            var bar_width = Math.floor(draw_area/ temperatures.length);

            var nv = []; //normalized temperatures
            var max = temperatures[0];
            for(var i = 1; i<5; i++){
                max = Math.max(max,temperatures[i]);
            }
            for(var i = 0; i<5; i++)
                nv[i] = (highest/max)*temperatures[i];

            for(var i = 0; i < 5; i++){
                ctx.fillStyle = "grey";
                ctx.fillText(label[i], draw_margin + bar_width * (i), labels_start);
            }


            for(var i = 0; i<5; i++){
                ctx.fillStyle = "lightgrey";
                ctx.fillRect(draw_margin + bar_width * (i), line.start_y -nv[i], bar_width, nv[i]);
            }
            ctx.fillStyle = line.color;
            ctx.fillRect(
                line.start_x,
                line.start_y,
                line.width,
                line.height
            );

            // temperature colored rectangle



        }
    };