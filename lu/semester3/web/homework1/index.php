<?php
if(
	isset($_GET['amount']) and
	isset($_GET['source']) and
	isset($_GET['target']) and
) {
    $amount = $_GET["amount"];
    $source = $_GET["source"];
    $target = $_GET["target"];
    echo "You asked to convert $amount $source into $target";

	$XML=simplexml_load_file("http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml");
	        
	foreach($XML->Cube->Cube->Cube as $rate){
		if ($rate["currency"] == $target){
			echo 'rate is ', $rate["rate"];
			// echo 'hey, this would be ', ($amount * 100000) / ($rate["rate"] * 100000), ' in euro!';
		}
	    // echo '1&euro;='.$rate["rate"].' '.$rate["currency"].'<br/>';
	}    
}

$result_status = ""; //valid values: empty string, "success", "error"
$result_message = "";
$target_currencies = array('LVL', 'GBP', 'RUB', 'CHF', 'SEK', 'NOK', 'JPY', 'LTL');

require("view.php");

?>