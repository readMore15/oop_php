<?php

class Address{

	const PERSON_STATUS_STUDENT = 1;
	const PERSON_STATUS_EMPLOYEE = 2;
	const PERSON_STATUS_OWNER = 3;

	static public $person_status = array(
		Address::PERSON_STATUS_STUDENT => 'Student',
		Address::PERSON_STATUS_EMPLOYEE => 'Employee',
		Address::PERSON_STATUS_OWNER => 'Owner'
	);

	public $name;
	public $middle_name;
	public $last_name;
	public $birth_date;
	public $birth_month;
	protected $_birth_year;

	protected $_person_status_id;

	protected $_time_created;
	protected $_time_updated;

	function __construct(){
		$this->_time_created = time();
	}

	function __get($current){
		if(!$this->_birth_year){
			$this->_birth_year = $this->_birth_year_guess();
		}

		$protected_birth_year = '_' . $current;
		if( property_exists($this, $protected_birth_year)){
			return $this->$protected_birth_year;
		}

		trigger_error('No such string via __get: '. $current);
		return NULL;
	}

	protected function _birth_year_guess(){
		return 'LOOKUP';
	}

	function __set($current, $value){
		if( 'person_status_id' == $current ){
			$this->_setPersonStatusId($value);
			return;
		}

		if('birth_year' == $current){
			$this->$current = $value;
			return;
		}

		trigger_error('Undefined string __set: ' . $current);
	}

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

	static public function isPersonStatusValid($person_status_id){
		return array_key_exists($person_status_id, self::$person_status);
	}

	protected function _setPersonStatusId($person_status_id){
		if( self::isPersonStatusValid($person_status_id) ){
			$this->_person_status_id = $person_status_id;
		}
	}

}