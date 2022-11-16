<?php

// Include Database
require_once("connection.php");
session_start();

	/*
		msg0 = Successful
		msg1 = Empty fields
		msg2 = Username is invalid
		msg3 = Password must be atleast 8 or more characters
		msg4 = Incorrect password.
		msg5 = Invalid Credentials
	*/

	$username = $_POST['usernameL'];
	$password = $_POST['passL'];

	if (isset($username) && isset($password)){


		if(empty($username) || empty($password) ||
		   $username == "" || $password == "" ){
			$data['msg'] = 1;
		}
		else if (!preg_match('/^[a-zA-Z0-9]+([_-]?[a-zA-Z0-9])*$/', $username)){
			$data['msg'] = 2;
		}
		else if (strlen($password) <= 7){
			$data['msg'] = 3;
		}
		else{

			// Checks if they are valid.
			$usernameSql = mysqli_query($con, "SELECT * FROM tb_users WHERE username = '$username'");

			if(mysqli_num_rows($usernameSql) === 1){

				$row = mysqli_fetch_assoc($usernameSql);
				$hashedPass = $row['password'];

				if (password_verify($password, $hashedPass)){
					$userID = $row['userID'];
					$_SESSION["userID"] = $userID;
					$data['msg'] = 0;
				}
				else{
					$data['msg'] = 4;
				}
			}

			else{
				$data['msg'] = 5;
			}
		}
		echo json_encode($data);
	}

?>