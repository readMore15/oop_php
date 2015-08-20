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

		/*echo '<pre>';
		echo var_export($address);
		echo '</pre>';*/

		echo $address->display_details();

	?>

</body>
</html>