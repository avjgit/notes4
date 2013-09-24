<?php

/**
 * This is the main file which receives and analyzes data, 
 * generates response data and finally calls the template.
 */


//Your code goes here


$result_status = ""; //valid values: empty string, "success", "error"
$result_message = "";
$target_currencies = array('LVL', 'GBP', 'RUB', 'CHF', 'SEK', 'NOK', 'JPY', 'LTL');

require("view.php");