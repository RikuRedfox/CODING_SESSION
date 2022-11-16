<?php

// Include Database
require_once("connection.php");

		
	/*
		msg0 = Successful
		msg1 = Empty fields
		msg2 = Username has more words
		msg3 = Username only takes a-z A-Z
		msg4 = E-mail is invalid
		msg5 = Password must be atleast 8 or more characters
		msg6 = Password does not match
		msg7 = Username contains Bad Words
		msg8 = Email taken
		msg9 = Something went wrong inserting values to database.
		msg10 = Username exceeds at limit
		msg10 = Invalid Full Name
	*/

	$fullname = ucwords($_POST['rfullN']);
	$username = $_POST['rUserN'];
	$email = $_POST['rEmail'];
	$password = $_POST['rPass'];
	$confirmPassword = $_POST['rRPass'];

	if (isset($fullname) && isset($username) && isset($email) && isset($password) && isset($confirmPassword)){


		if(empty($fullname) || empty($username) || empty($email) || empty($password) || empty($confirmPassword) ||
			$fullname == "" || $username == "" || $email == "" || $password == "" || $confirmPassword == ""){
			$data['msg'] = 1;
		}
		else if (!preg_match("/^[A-Za-z\s]{1,}[\.]{0,1}[A-Za-z\s]{0,}$/", $fullname)){
			$data['msg'] = 11;
		}
		else if (strpos(trim($username), ' ') !== false){
			$data['msg'] = 2;
		}
		else if (!preg_match('/^[a-zA-Z0-9]+([_-]?[a-zA-Z0-9])*$/', $username)){
			$data['msg'] = 3;
		}
		else if (strlen($username) > 15){
			$data['msg'] = 10;
		}
		else if (!preg_match('/^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/', $email)){
			$data['msg'] = 4;
		}
		else if (strlen($password) <= 7 || strlen($confirmPassword) <= 7){
			$data['msg'] = 5;
		}
		else if ($password != $confirmPassword){
			$data['msg'] = 6;
		}
		else{
			// badwords
			$badWords = array("fuck", "fo", "pakening", "bobo", "vovo", "tanga", "putangina", "putang ina", "puta", "tarantado", "siraulo", "tangina", "taena", 'gago', 'gaga', 'tite', 'pepe', 'dede', "d3d3", 'kantot', 'kantut', 'kantutan', 'kantotan', 'tit3', 'p3p3', 'titi', 'fvck', "inutil", "fucker", "tado", "fvk", "sex");

			$allowRun = true;
			foreach($badWords as $elem){
				$lower = strtolower($username);

				if (str_contains($lower, $elem)){
					$data['msg'] = 7;
					$allowRun = false;
				}
			}

			if($allowRun){
				// Checks if EMAIL is taken.
				$usernameSql = mysqli_query($con, "SELECT email FROM tb_users WHERE email = '$email'");

				if(mysqli_num_rows($usernameSql) !== 1){

					$fullname = htmlspecialchars(mysqli_real_escape_string($con, $fullname));
					$username = htmlspecialchars(mysqli_real_escape_string($con, $username));
					$email = htmlspecialchars(mysqli_real_escape_string($con, $email));
					$password = htmlspecialchars(mysqli_real_escape_string($con, $password));
					$hashPass = password_hash($password, PASSWORD_DEFAULT);

					// Insert User into database UwU
					$insertSql = mysqli_query($con, "INSERT INTO tb_users (fullname, username, email, password, pow)
																	  VALUES ('$fullname', '$username', '$email', '$hashPass', 0)");

					if ($insertSql == true){
						$data['msg'] = 0;
					}
					else{
						$data['msg'] = 9;
					}
				}

				else{
					$data['msg'] = 8;
				}
			}
		}
		echo json_encode($data);
	}

?>