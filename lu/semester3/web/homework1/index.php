<?php

$eur_source = "http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml";
$lvl_source = "http://www.bank.lv/vk/xml.xml";
$eur_amount = 0;

function get_currencies(){
	global $eur_source, $lvl_source;

	$XML=simplexml_load_file($eur_source);
	foreach($XML->Cube->Cube->Cube as $rate){
		$target_currencies[] = $rate["currency"];
	}
	$XML=simplexml_load_file($lvl_source);
	foreach ($XML->xpath('//Currency') as $rate) {
		$target_currencies[] = (string)$rate->ID;
	}
	asort($target_currencies);
	return array_unique($target_currencies);
}

function error_data(){
    $GLOBALS['result_status'] = "error";
    $GLOBALS['result_message'] = "Could not get currency data.";
}

function check_error_rate(){
    if($GLOBALS['result_status'] == ""){
	    $GLOBALS['result_status'] = "error";
    	$GLOBALS['result_message'] = "Got currency data, but there is no rate for your currency.";
	}
}

function success($target_amount){
	global $result_status, $result_message, $amount, $source;
	$result_status = "success";
	$result_message = 'For your ' . $amount . ' ' . $source . ' you can buy ' . $target_amount;
}

function to_eur($amount, $source){
	global $eur_source, $eur_amount;

    $XML=simplexml_load_file($eur_source);

    if(isset($XML)){
        foreach($XML->Cube->Cube->Cube as $rate){
            if ($rate["currency"] == $source){
            	$eur_amount = round( $amount / floatval($rate["rate"]), 2);
                success( $eur_amount . ' EUR.');
            }
        }
		check_error_rate();
    }
    else {
		error_data();
    }
}

function to_lvl($amount, $source){
	global $lvl_source;

    $XML=simplexml_load_file($lvl_source);

    if(isset($XML)){
        foreach ($XML->xpath('//Currency') as $rate) {
        	if ((string)$rate->ID == $source){
                $lvl_amount = round( $amount * (floatval($rate->Rate) / floatval($rate->Units)), 2);
                success( $lvl_amount . ' LVL.');
        	}
        }
		check_error_rate();
    }
    else {
		error_data();
    }
}

$result_status = ""; //valid values: empty string, "success", "error"
$result_message = "";
$target_currencies = get_currencies();

if(
    isset($_GET['amount']) and
    isset($_GET['source']) and
    isset($_GET['target'])
) {
    $amount = $_GET["amount"];
    $source = $_GET["source"];
    $target = $_GET["target"];

    if ($target == $source){
    	success( $amount . ' ' . $target);
    }
    elseif ($target == 'EUR'){
    	to_eur($amount, $source);
    }
    elseif ($target == 'LVL') {
    	to_lvl($amount, $source);
    }
    elseif ($target == 'Gold') {
    	// plan: a) first, convert currency into eur, b) then into gold
    	// example: 1 lvl to gold:
    	// a) 1 lvl - rate .7026 => 1.42 eur
    	// b) at 979 eur per ouce, for 1.42 you can get ... 0.0015 ounces

    	// Step 1 of 2: convert currency to EUR
    	if ($source == 'EUR') {
    		$result_status = "success";
    		$eur_amount = $amount;
    	}
    	else {
    		to_eur($amount, $source);
		}

    	if ($result_status == "success") {

	    	// Step 2 of 2: convert EUR to gold
	    	$goldrates = file_get_contents('http://www.goldfixing.com/vars/goldfixing.vars');

			if(isset($goldrates)){
		    	$goldrates = str_replace(" ", "", $goldrates);
		    	$goldrates = str_replace("&", "", $goldrates);
		    	$price_flag = 'pmeuro=';
				$price_flag_start = strpos($goldrates, $price_flag);
				$goldprice = substr($goldrates, $price_flag_start + strlen($price_flag));
				$goldounces = round($eur_amount/ floatval($goldprice), 4);
				$ounce_grams = 31.1034768;
				$goldgrams = round($goldounces * $ounce_grams, 4);

				success($goldounces . ' Troy ounces or ' . $goldgrams . ' grams of gold.');

			    if($result_status == ""){
					check_error_rate();
			    }
			}
			else {
				error_data();
			}
		}
    }
}

require("view.php");

?>