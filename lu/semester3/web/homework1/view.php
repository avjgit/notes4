<?php
 //If "result_status" is not set, most likely the user has opened the
 // template.php file directly. We don't want to allow this.
 if (!isset($result_status)) {
     header("Location:index.php");
 }
?><!DOCTYPE html>
<html lang="en">
    <head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta name="description" content="Currency converter">
	<meta name="author" content="">
	<title>Currency converter</title>

	<!-- Bootstrap core CSS -->
	<link href="//netdna.bootstrapcdn.com/bootstrap/3.0.0/css/bootstrap.min.css" rel="stylesheet">
	<link href="convert.css" rel="stylesheet">

	<!-- HTML5 shim and Respond.js IE8 support of HTML5 elements and media queries -->
	<!--[if lt IE 9]>
	  <script src="//cdnjs.cloudflare.com/ajax/libs/html5shiv/3.6.2/html5shiv.js"></script>
	  <script src="//cdnjs.cloudflare.com/ajax/libs/respond.js/1.3.0/respond.js"></script>
	<![endif]-->
    </head>

    <body>

	<div class="container">

	    <form class="form-signin" method="GET">

		<?php
		if ($result_status == "success") { ?>
		<div class="panel panel-success">
		    <div class="panel-heading">
		    <h4>Calculation result</h4>
		    </div>
		    <div class="panel-body">
		    <p><?php echo htmlspecialchars($result_message)?></p>
		    </div>

		</div>
		<?php } elseif ($result_status == "error") {?>
		<div class="panel panel-warning">
		    <div class="panel-heading">
		    <h4>Problem detected!</h4>
		    </div>
		    <div class="panel-body">
			<p><?php echo htmlspecialchars($result_message)?></p>
		    </div>

		</div>
		<?php } ?>

		<h2 class="form-signin-heading">Please, convert</h2>
		<div class="form-group">
		    <input type="text" name="amount" id="amount"class="form-control" placeholder="This amount of..." autofocus>
		</div>

		<div class="form-group" >

		    <select class="form-control" name="source">
			<option>... this currency</option>
			<?php
			foreach ($target_currencies as $currency) {
			    echo '<option>' . $currency . '</option>'."\r\n";
			}
			?>
		    </select>
		</div>


		<div class="form-group" >
		    <h2 class="form-signin-heading">into: </h2>
		    <label for="targetLVL">
			<input type="radio" name="target" value="LVL" id="targetLVL">
			LVL
		    </label>
		    <label for="targetEUR">
			<input type="radio" name="target" value="EUR" id="targetEUR">
			EUR
		    </label>
		    <label for="targetGold">
			<input type="radio" name="target" value="Gold" id="targetGold">
			Troy ounces
		    </label>
		</div>
		<button class="btn btn-lg btn-primary btn-block" type="submit" onclick="is_currency_valid()">Submit</button>


	    </form>

	</div> <!-- /container -->

    </body>
</html>

<script type="text/javascript">
	function is_currency_valid(){
		alert(document.getElementsByName("source")[0].value);

	}
</script>