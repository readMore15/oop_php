<?php

class Address{
	public $name;
	public $middle_name;
	public $last_name;
	public $birth_date;
	public $birth_month;
	public $birth_year;

	function display_details(){
		$output = '';

		$output .= $this->name;
		$output .= ' ' . $this->middle_name . ' ';
		$output .= $this->last_name . '<br>';

		$output .= $this->birth_date . ' ';
		$output .= $this->birth_month . ', ';
		$output .= $this->birth_year;

		return $output;

	}

}