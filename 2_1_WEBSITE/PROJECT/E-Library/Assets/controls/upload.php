<?php
	require_once("connection.php");
	session_start();

	/*
		msg0 = Upload Success
		msg1 = Empty Fields
		msg2 = Not a Pdf File
		msg3 = Upload Failed
		msg4 = Invalid Password
		msg5 = Query Error
	*/

	$path = "../Uploads/pdfFiles/";
	$file = $_FILES['File'];
	$name = explode(".", $_FILES["File"]["name"]);
	$fileExt = $_FILES["File"]["name"];
	$tmp_name = $_FILES['File']['tmp_name'];
	$fileName = round(microtime(true)) . '.' . end($name);
	$ext = pathinfo($fileExt, PATHINFO_EXTENSION);

	if (!isset($_FILES) || empty($_FILES) || !isset($_POST['Title']) || empty($_POST['Title']) || !isset($_POST['Contributors']) || empty($_POST['Contributors']) || !isset($_POST['Password']) || empty($_POST['Password'])) {
		$data['msg'] = 1;
	}
	else if ($ext != "pdf" && $ext != "PDF"){
		$data['msg'] = 2;
	}
	else{
	    $path = "../Uploads/pdfFiles/";
		$file = $_FILES['File'];
		$name = explode(".", $_FILES["File"]["name"]);
		$tmp_name = $_FILES['File']['tmp_name'];
		$fileName = round(microtime(true)) . '.' . end($name);

		$fileTitle = htmlspecialchars(mysqli_real_escape_string($con, $_POST['Title']));
		$fileContributors = ucwords(htmlspecialchars(mysqli_real_escape_string($con, $_POST['Contributors'])));
		$password = $_POST['Password'];
		$userID = $_SESSION['userID'];

		/// Check if password matched to the user who is logged in
		// Collect the identity
		$userQuery = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = '$userID'");

		if (mysqli_num_rows($userQuery) === 1){

			$row = mysqli_fetch_assoc($userQuery);
			$hashedPass = $row['password'];
			$date = date("Y-m-d h:i:s");

			if (password_verify($password, $hashedPass)){
				if ( move_uploaded_file($tmp_name, $path.$fileName) ){

					$uploadQuery = mysqli_query($con, " INSERT INTO tb_files (fileName, fileTitle, fileContributors, userID, report, published)
														VALUES ('$fileName', '$fileTitle', '$fileContributors', '$userID', 0, '".date("Y-m-d h:i:s")."') ");
					if ($uploadQuery){
						$data['msg'] = 0;
					}
					else{
						$data['msg'] = 5;
					}
					
				} 
				else{
					$data['msg'] = 3;
				}
			}
			else{
				$data['msg'] = 4;
			}
		}
	}

	echo json_encode($data);