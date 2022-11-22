<?php
	require_once("../connection.php");
	session_start();

	/*
		msg0 = Delete Success
		msg1 = Delete Failed (Query)
		msg2 = No User Found 
	*/

	if (isset($_POST['ID'])){
		$data['msg'] = "ID of the User is: ".$_POST['ID'];
		$id = $_POST['ID'];
		$selectFile = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = $id");

		if (mysqli_num_rows($selectFile) === 1){
			$row = mysqli_fetch_assoc($selectFile);
			$uId = $row['userID'];
			
			if ($deleteData = mysqli_query($con, "DELETE FROM tb_users WHERE userID = $uId")){
				$data['msg'] = 0;
			}
			else{
				$data['msg'] = 1;
			}
				
		}
		else{
			$data['msg'] = 2;
		}

	}
	echo json_encode($data);