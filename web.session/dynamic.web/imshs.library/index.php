<?php
	require_once("Assets/controls/connection.php");
	session_start();

	if (!isset($_SESSION['userID'])){
		header("location: session.php");
	}
	else{

		$userID = $_SESSION['userID'];
		$selPerson = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = $userID");
		$user = mysqli_fetch_assoc($selPerson);

        
        // Check if the user doesnt exist in the database
        $checkUser = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = '$userID'");
        if (mysqli_num_rows($checkUser) === 1){
            $msgHandler = "exist";
        }
        else{
            header("location: Assets/controls/logout.php");
        }

		/// Delete Files from non existing accounts
		$deleteCom = mysqli_query($con, "DELETE FROM tb_files WHERE (userID) NOT IN (SELECT userID FROM tb_users)");

		/// Delete Report Files from non existing Files
		$deleteCom = mysqli_query($con, "DELETE FROM tb_reports WHERE (userID) NOT IN (SELECT userID FROM tb_files)");

        /// Count Reports
        $countReport = mysqli_query($con, "SELECT * FROM tb_reports");
        $reportNum = mysqli_num_rows($countReport);
	}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
	<title>Easy Research</title>

	<!-- Embedded CDN's -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
	<link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.10.25/css/jquery.dataTables.min.css">
	<link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/responsive/2.2.9/css/responsive.dataTables.min.css">

	<!-- External CSS -->
	<!-- Nav -->
	<link rel="stylesheet" type="text/css" href="Assets/css/variables.css">
	<link rel="stylesheet" type="text/css" href="Assets/css/main.css">

	<!-- Embedded CDN's -->
	<script src="https://code.jquery.com/jquery-3.6.0.min.js" integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>	
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
	<script type="text/javascript" charset="utf8" src="https://cdn.datatables.net/1.10.25/js/jquery.dataTables.js"></script>
	<script type="text/javascript" charset="utf8" src="https://cdn.datatables.net/responsive/2.2.9/js/dataTables.responsive.min.js"></script>

</head>
<body>
	<!-- Intro -->
	<div class="bg-pink intro">
		<div class="txtContainer">
			<h1 class="d-3 text-white introTxt">Easy Research</h1>
		</div>
	</div>

	<!-- Nav -->
	<?php
		include_once("Assets/controls/parts/nav.php");
	?>

	<!-- Section -->
	<div class="container my-4 ">
		<!-- Content -->
		<div class="row d-flex justify-content-around">
			<!-- Selection -->
			<div class="col col-12 col-sm-12 col-md-12 col-lg-4 col-xl-3 my-2">
				<div class="bg-pink">
					<!-- Menu -->
					<div class="bg-pink">

						<!-- Button -->
						<div class="list-group" id="list-tab" role="tablist">

					      	<a class="library list-group-item active list-group-item-action" id="list-library-list" data-toggle="list" href="#list-library" role="tab">
					      		Library
					      	</a>

					      	<a class="research list-group-item list-group-item-action" id="list-research-list" data-toggle="list" href="#list-research" role="tab">
					      		My Research
					      	</a>

					      	<a class="research list-group-item list-group-item-action" id="list-upload-list" data-toggle="list" href="#list-upload" role="tab">
					      		Upload
					      	</a>
					      	<?php
					      	if ($user['pow'] == 1){ ?>
					      	<a class="users list-group-item list-group-item-action" id="list-users-list" data-toggle="list" href="#list-users" role="tab">
					      		All Users
					      	</a>
					      	<?php
					      	} ?>

					      	<?php
					      	if ($user['pow'] == 1){ ?>
					      	<a class="reports list-group-item d-flex justify-content-between align-items-center list-group-item-action" id="list-reports-list" data-toggle="list" href="#list-reports" role="tab">
					      		Reports

					      		<?php 
					      		if ($reportNum > 0){ ?>
					      		<span class="badge badge-danger badge-pill"><?php echo $reportNum ?></span>
					      		<?php
					      		} else{ ?>
					      		<span></span>
					      		<?php 
					      		} ?>
					      	</a>
					      	<?php
					      	} ?>

					      	<a class="reports list-group-item d-flex justify-content-between align-items-center list-group-item-action" href="Assets/controls/logout.php">
					      		Logout
					      	</a>

					    </div>

					</div>
				</div>
			</div>
			<!-- Displayer -->

			<div class="col col-12 col-sm-12 col-md-12 col-lg-8 col-xl-9 my-2" id="displayer">
				<div class="container-fluid bg-pink">
					<!-- Display here -->
					<div class="jumbotron-fluid bg-pink rounded">

						<!-- Tabs -->
						<div class="tab-content p-2" id="nav-tabContent">

					      	<div class="tab-pane fade show active bg-white p-3 rounded" id="list-library">

					      		<h3 class="lead d-3 m-2 text-center">Research Library</h3>

					      		<table class="display my-2" style="width: 100%">
								    <thead>
								        <tr>
								            <th>File ID</th>
								            <th>Title</th>
								            <th>Author</th>
								            <th>Published</th>
								            <th>Contributors</th>
								            <th>Actions</th>
								        </tr>
								    </thead>
								    <tbody>
								    <!-- Generate table row -->
								    <?php 
									$query = mysqli_query($con, "SELECT * FROM tb_files");
									while($row = mysqli_fetch_assoc($query)){
										$owner = $row['userID'];
										$selOwner = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = $owner");
										$author = mysqli_fetch_assoc($selOwner);
										$str = $row['fileContributors'];
										$arr = explode("*", $str);
										$res = "";
										$date = $row['published'];
										$datePublished = date("Y-m-d",strtotime($date));

										for ($i = 0; $i < count($arr); $i++){
											if ($i == count($arr)-1){
												$res .= "<br> ".$arr[$i];
											}
											else $res .= "<br> ".$arr[$i].", ";
										}
										$contributors = $res;
									?>
										<tr>
											<td><?php echo $row['fileID'] ?></td>
											<td><?php echo $row['fileTitle'] ?></td>
											<td><?php echo $author['fullname'] ?></td>
											<td><?php echo $datePublished ?></td>
											<td><?php echo $contributors ?></td>
											<td><button class='btn btn-primary' onclick="viewFile(<?php echo $row['fileID'] ?>)">View</button>
												<?php 
												if ($row['userID'] != $userID){ // If user is not equal to the userID of Files?>
												<button class='btn btn-warning' onclick="reportFile(<?php echo $row['fileID'] ?>)">Report</button>
												<?php
												} ?>

												<?php 
												if ($user['pow'] == 1){ // If we are admin?>
												<button class='btn btn-danger' onclick="deleteFile(<?php echo $row['fileID'] ?>)">Delete</button></td>
												<?php
												} else if ($row['userID'] == $userID){ // If we are the owner?>
												<button class='btn btn-danger' onclick="deleteFile(<?php echo $row['fileID'] ?>)">Delete</button></td>
												<?php
												} else { // Close ?>
												</td>
												<?php
												} ?>

										</tr>
									<?php
									}
								    ?>
								    </tbody>
								</table>

					      	</div>

					      	<div class="tab-pane fade bg-white p-3 rounded" id="list-research">
					      		<h3 class="lead d-3 m-2 text-center">My Research</h3>

					      		<table class="display my-2" style="width: 100%">
								    <thead>
								        <tr>
								            <th>File ID</th>
								            <th>Title</th>
								            <th>Author</th>
								            <th>Published</th>
								            <th>Contributors</th>
								            <th>Actions</th>
								        </tr>
								    </thead>
								    <tbody>
								    <!-- Generate table row -->
								    <?php 
									$query = mysqli_query($con, "SELECT * FROM tb_files where userID = $userID");
									while($row = mysqli_fetch_assoc($query)){
										$owner = $row['userID'];
										$selOwner = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = $owner");
										$author = mysqli_fetch_assoc($selOwner);
										$str = $row['fileContributors'];
										$arr = explode("*", $str);
										$res = "";
										$date = $row['published'];
										$datePublished = date("Y-m-d",strtotime($date));

										for ($i = 0; $i < count($arr); $i++){
											if ($i == count($arr)-1){
												$res .= "<br> ".$arr[$i];
											}
											else $res .= "<br> ".$arr[$i].", ";
										}
										$contributors = ucwords($res);
									?>
										<tr>
											<td><?php echo $row['fileID'] ?></td>
											<td><?php echo $row['fileTitle'] ?></td>
											<td><?php echo $author['fullname'] ?></td>
											<td><?php echo $datePublished ?></td>
											<td><?php echo $contributors ?></td>
											<td>
												<button class='btn btn-primary' onclick="viewFile(<?php echo $row['fileID'] ?>)">View</button>
												<button class='btn btn-danger' onclick="deleteFile(<?php echo $row['fileID'] ?>)">Delete</button>
											</td>

										</tr>
									<?php
									}
								    ?>
								    </tbody>
								</table>
					      	</div>

					      	<div class="tab-pane fade bg-white p-3 rounded" id="list-upload">
					      		<h3 class="lead d-3 m-2 text-center">Upload</h3>

					      		<form class="form" id="upload" enctype="multipart/form-data">

					      			<div class="form-group row">
								  		<div class="my-2 col-12 col-sm-12 col-md-6 col-lg-6 col-xl-8">
								  			<label for="Title">Title: </label>
										    <input type="text" class="form-control form-control-sm title" name="Title" placeholder="Enter Title">
								  		</div>

								  		<div class="my-2 col-12 col-sm-12 col-md-6 col-lg-6 col-xl-4">
										  	<label class="pdf-file-label" for="customFile">Upload a PDF File: </label>
										  	<input type="file" class="form-control form-control-sm pdfFileUpload" accept="application/pdf">
										</div>
					      			</div>

								  	<div class="form-group form-row">
								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 contributor1">
								  			<label for="contributor1">Contributor: </label>
										    <input type="text" class="form-control form-control-sm" id="contributor1" placeholder="Enter Full Name">
								  		</div>
								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 d-none contributor2">
								  			<label for="contributor2">Contributor: </label>
										    <input type="text" class="form-control form-control-sm " id="contributor2" placeholder="Enter Full Name">
								  		</div>
								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 d-none contributor3">
								  			<label for="contributor3">Contributor: </label>
										    <input type="text" class="form-control form-control-sm" id="contributor3" placeholder="Enter Full Name">
								  		</div>
								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 d-none contributor4">
								  			<label for="contributor4">Contributor: </label>
										    <input type="text" class="form-control form-control-sm" id="contributor4" placeholder="Enter Full Name">
								  		</div>
								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 d-none contributor5">
								  			<label for="contributor5">Contributor: </label>
										    <input type="text" class="form-control form-control-sm" id="contributor5" placeholder="Enter Full Name">
								  		</div>
								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 d-none contributor6">
								  			<label for="contributor6">Contributor: </label>
										    <input type="text" class="form-control form-control-sm" id="contributor6" placeholder="Enter Full Name">
								  		</div>
								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 d-none contributor7">
								  			<label for="contributor7">Contributor: </label>
										    <input type="text" class="form-control form-control-sm" id="contributor7" placeholder="Enter Full Name">
								  		</div>
								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 d-none contributor8">
								  			<label for="contributor8">Contributor: </label>
										    <input type="text" class="form-control form-control-sm" id="contributor8" placeholder="Enter Full Name">
								  		</div>

								  		<div class="col-12 col-sm-12 col-md-6 col-lg-4 col-xl-4 mt-4">
										    <input type="button" class="form-control form-control-sm mb-4 btn btn-primary" id="addContributor" value="Add more">
								  		</div>
								  	</div>

								  	<div class="form-group">
									    <label for="pass">Your Account Password <small>To confirm the file</small></label>
									    <input type="password" name="Password" class="form-control form-control-sm pass" id="pass" placeholder="Password">
								  	</div>

								  	<button type="submit" id="pdfUpload" name="uploadFile" class="btn btn-primary">Submit</button>
								</form>
					      	</div>
					      	<?php
					      	if ($user['pow'] == 1){ ?>
					      	<div class="tab-pane fade bg-white p-3 rounded" id="list-users">

					      		<h3 class="lead d-3 m-2 text-center">Users</h3>

					      		<table class="display my-2" style="width: 100%">
								    <thead>
								        <tr>
								            <th>#ID</th>
								            <th>Full Name</th>
								            <th>Username</th>
								            <th>E-mail</th>
								            <th>Power</th>
								            <?php 
											if ($user['pow'] == 1){ ?>
											<th>Delete</th>
											<?php
											} ?>
								        </tr>
								    </thead>
								    <tbody>
								    <!-- Generate table row -->
								    <?php 
									$query = mysqli_query($con, "SELECT * FROM tb_users ORDER BY fullname");
									while($row = mysqli_fetch_assoc($query)){
									?>
										<tr>
											<td><?php echo $row['userID'] ?></td>
											<td><?php echo $row['fullname'] ?></td>
											<td><?php echo $row['username'] ?></td>
											<td><?php echo $row['email'] ?></td>
											<td><?php echo $row['pow'] ?></td>
											<?php 
											if ($user['pow'] == 1){ ?>
											<td><button class='btn btn-danger' onclick="removeUser(<?php echo $row['userID'] ?>)">Delete</button></td>
											<?php
											} ?>

										</tr>
									<?php
									}
								    ?>
								    </tbody>
								</table>

					      	</div>
					      	<?php
					      	} ?>

					      	<?php
					      	if ($user['pow'] == 1){ ?>
					      	<div class="tab-pane fade bg-white p-3 rounded" id="list-reports">
					      		<h3 class="lead d-3 m-2 text-center">Reports</h3>

					      		<table class="display my-2" style="width: 100%">
								    <thead>
								        <tr>
								            <th>#File ID</th>
								            <th>File Name</th>
								            <th>Author Name</th>
								            <th>Reports</th>
								            <th>Latest Report</th>
								            <th>Reason</th>
								            <th>Actions</th>
								        </tr>
								    </thead>
								    <tbody>
								        <!-- Generate table row -->
								    <?php 
									$query = mysqli_query($con, "SELECT * FROM tb_reports");
									while($row = mysqli_fetch_assoc($query)){
									$owner = $row['userID'];
									$selOwner = mysqli_query($con, "SELECT * FROM tb_users WHERE userID = $owner");
									$author = mysqli_fetch_assoc($selOwner);
									$date = $row['fileTime'];
									$str = $row['fileReason'];
									$arr = explode("*", $str);
									$res = "";
									$date = $row['fileTime'];
									$datePublished = date("Y-m-d",strtotime($date));

									for ($i = 0; $i < count($arr); $i++){
										if (count($arr) == 1){
											$res .= $arr[$i].".";
										}
										else if ($i == count($arr)-1){
											$res .= " and ".$arr[$i].".";
										}
										else $res .= $arr[$i].", ";
									}
									$rason = $res;

									echo "
										<tr>
											<td>".$row['fileID']."</td>
											<td>".$row['fileName']."</td>
											<td>".$author['fullname']."</td>
											<td>".$row['fileReportCount']."</td>
											<td>".$datePublished."</td>
											<td>".$rason."</td>
											<td>
												<button class='btn btn-primary' onclick='viewFile(".$row['fileID'].")'>View</button>
												<button class='btn btn-success' onclick='deleteReport(".$row['fileID'].")'>Keep</button>
											</td>
										</tr>
									";
									}
								    ?>
								    </tbody>
								</table>
					      	</div>
					      	<?php
					      	} ?>
					    </div>
					</div>
				</div>
			</div>
		</div>
	</div>

	<!-- Modals -->
	
<!-- CDN JS -->
<script src="//cdn.jsdelivr.net/npm/sweetalert2@11"></script>

<!-- External JS -->
<script type="text/javascript" src="Assets/js/library.js"></script>
<script type="text/javascript" src="Assets/js/main.js"></script>
<script type="text/javascript" src="Assets/js/action.js"></script>
<script>$('.display').addClass('responsive nowrap table-striped');</script>

</body>
</html>
