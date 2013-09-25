<?php

$result_status = ""; //valid values: empty string, "success", "error"
$result_message = "";
$target_currencies = array('LVL', 'GBP', 'RUB', 'CHF', 'SEK', 'NOK', 'JPY', 'LTL');

if(
    isset($_GET['amount']) and
    isset($_GET['source']) and
    isset($_GET['target'])
) {
    $amount = $_GET["amount"];
    $source = $_GET["source"];
    $target = $_GET["target"];

    if ($target == 'EUR'){
        $XML=simplexml_load_file("http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml");

        if(isset($XML)){
            foreach($XML->Cube->Cube->Cube as $rate){
                if ($rate["currency"] == $source){
                    $result_status = "success";
	                $result_message = round( $amount / floatval($rate["rate"]), 2);
                }
            }
            if($result_status == ""){
                $result_status = "error";
                $result_message = "Got currency data, but there is no rate for your currency.";
            }
        }
        else {
            $result_status = "error";
            $result_message = "Could not get currency data.";
        }

    }
    elseif ($target == 'LVL') {
        $XML=simplexml_load_file("http://www.bank.lv/vk/xml.xml");

        if(isset($XML)){
            foreach ($XML->xpath('//Currency') as $rate) {
            	if ((string)$rate->ID == $source){
                    $result_status = "success";
                    $result_message = round( $amount * floatval($rate->Rate), 2);
            	}
            }
            if($result_status == ""){
            	echo 'not converted';
                $result_status = "error";
                $result_message = "Got currency data, but there is no rate for your currency.";
            }
        }
        else {
            $result_status = "error";
            $result_message = "Could not get currency data.";
        }
    }
    elseif ($target == 'Gold') {
        // $XML=simplexml_load_file("http://www.bank.lv/vk/xml.xml");
    	echo 'inside gold!';
    	// plan: a) first, convert currency into eur, b) then into gold
    	// a)
    	// ...
    	// b)
    	$homepage = file_get_contents('http://www.goldfixing.com/vars/goldfixing.vars');
		echo $homepage;

        if(isset($XML)){
            // foreach ($XML->xpath('//Currency') as $rate) {
            // 	if ((string)$rate->ID == $source){
            //         $result_status = "success";
            //         $result_message = round( $amount * floatval($rate->Rate), 2);
            // 	}
            // }
            if($result_status == ""){
            	echo 'not converted';
                $result_status = "error";
                $result_message = "Got currency data, but there is no rate for your currency.";
            }
        }
        else {
            $result_status = "error";
            $result_message = "Could not get currency data.";
        }
    }
}

require("view.php");

?>