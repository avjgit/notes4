<?php

$result_status = ""; //valid values: empty string, "success", "error"
$result_message = "";
$target_currencies = array('LVL', 'GBP', 'RUB', 'CHF', 'SEK', 'NOK', 'JPY', 'LTL');

if(
	isset($_GET['amount']) and
	isset($_GET['source']) and
	isset($_GET['target']) and
) {
    $amount = $_GET["amount"];
    $source = $_GET["source"];
    $target = $_GET["target"];
    echo "You asked to convert $amount $source into $target";

    if ($target == 'EUR'){    	
		$XML=simplexml_load_file("http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml");

		if(isset($XML)){
			foreach($XML->Cube->Cube->Cube as $rate){
				if ($rate["currency"] == $source){
					echo 'rate is ', $rate["rate"];
					$result_status = "success";
					$result_message = ($amount * 100000) / ($rate["rate"] * 100000);
					// echo 'hey, this would be ', $result_message, ' in euro!';
				}
			}   			
			if(!isset($result_status)){
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
			foreach(...){
				if ($rate["currency"] == $source){
					echo 'rate is ', $rate["rate"];
					$result_status = "success";
					$result_message = $amount * $rate["rate"]
					echo 'hey, this would be ', $result_message, ' in lats!';		
				}
			}      						
			if(!isset($result_status)){
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