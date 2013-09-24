<?php

/**
 * This is the main file which receives and analyzes data, 
 * generates response data and finally calls the template.
 */


//Your code goes here


if(isset($_GET['amount'])) {
    $amount = $_GET["amount"];
}

if(isset($_GET['source'])) {
    $source = $_GET["source"];
}

if(isset($_GET['target'])) {
    $target = $_GET["target"];
    echo "You asked to convert $amount $source into $target";
}


$result_status = ""; //valid values: empty string, "success", "error"
$result_message = "";
$target_currencies = array('LVL', 'GBP', 'RUB', 'CHF', 'SEK', 'NOK', 'JPY', 'LTL');

require("view.php");

?>