<html>
<head>
	<title>View Person Details</title>
</head>
<body>
<?php require 'class.Address.inc'; ?>

<?php

	$address = new Address;

	echo '<pre>';
	echo var_export($address);
	echo '</pre>';

?>

	<h2>Display Person Info</h2>

	<?php
		$address->name = 'Danemm';
		$address->middle_name = 'Mendoza';
		$address->last_name = 'Fabrigar';
		$address->birth_date = '25';
		$address->birth_month = 'Oct';
		$address->birth_year = '1988';
		$address->person_status_id = 3;

		echo '<pre>';
		echo var_export($address);
		echo '</pre>';

		echo $address->display_details();

	?>

	<h2>Testing magic method __get and __set</h2>

	<?php
		unset($address->birth_year);
		echo $address->display_details();
	?>

	<h2>Static word/Scope resolution</h2>

	<?php
		echo '<pre>';
		echo var_export(Address::$person_status);
		echo '</pre>';
	?>

	<h2>Testing static method</h2>

	<?php
		for ($i=0; $i <= 4; $i++) { 
			echo '<div>' . $i . ' is ';
			echo  Address::isPersonStatusValid($i) ? 'Valid' : 'Invalid';
			echo "</div>";
		}
	?>

</body>
</html>