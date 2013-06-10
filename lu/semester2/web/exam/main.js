window.onload = mainFunction;

function checkMandatory() {
    // alert("inside mandatory");

    var mandatory = ["name", "password", "special_field"];
    var i;
    var values = [];
    var is_valid = true;

    for (i = 0; i < mandatory.length; i++) {
        values[i] = document.getElementById(mandatory[i]).value;

        // alert(mandatory[i] + " value is " + values[i]);

        if (values[i] === 'undefined' ||
           values[i] === '') {
            alert("You should fill in " + mandatory[i] + ", it's mandatory!");

            // document.getElementById(mandatory[i]).style.border = "3px solid red";
            // manipulaton without external libraries
            document.getElementById(mandatory[i]).className = "error";

            is_valid = false;
        }
    }
    return is_valid;
}

function checkTypesRanges(){
    // alert("inside checktypesranges");

    var specialField = document.getElementById("special_field").value;
    var min = 41;
    var max = 43;

   if (specialField !== 'undefined' &&
       specialField !== '') {

        if (isNaN(specialField)) {
            alert("Actually, this special field should be a number!");
            return false;
        }

        if (specialField < min ||
            specialField > max) {
            alert("Special field has some special validity range:"+
                " between " + min + " and " + max + "."
            );
            return false;
        }
    }
    return true; //mandatory were checked before
}

function submitCheck()
{
    // alert("inside submitCheck");
    var mandatoryCheck = checkMandatory();
    var typesCheck = checkTypesRanges();
    // alert("ok");
    return mandatoryCheck && typesCheck;
}

function changeBtnName(){
    alert("changeBtnName");

    // if ($("#showbtn").value === "Show our licence agreement (in Latin)"){
    //     alert("true");
    // }
    // else{
    //     alert("false");
    // }
}

function mainFunction(){
    // document.getElementById("submit").onclick = function(){
        // checkMandatory() &&
        // checkTypesRanges();

        // var val = document.getElementById("name").value;
        // alert(val);
        // alert($("#name").value);

    // };


    // document.getElementById("form1").submit(function(){
        // return  checkMandatory() &&
        //         checkTypesRanges();
    // };
    $('#form1').submit(function(){
        // document.getElementById("form1").submit(function(){
        // document.getElementById("form1").submit(function(){
            return submitCheck();
    });

    document.getElementById("showbtn").onclick = function(){
        $("#licence").toggle();
        // $("#licence").toggle(fast, changeBtnName());
    };

    // manipulaton with external libraries
    document.getElementById("default").onclick = function(){
        $("#name").val("Anonymous");
        $("#password").val("asdf");
        $("#special_field").val("42");
    };

    document.getElementById("generate").onclick = function(){
        var newfield = document.createElement("input");
        newfield.type="text";
        var idname = new Date().getTime();
        newfield.id=idname;
        newfield.name=idname;
        var oldfield = document.getElementById("dynamicfields");
        oldfield.appendChild(newfield);

    };

}
