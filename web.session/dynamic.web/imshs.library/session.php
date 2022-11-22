<?php 
	require_once("Assets/controls/connection.php");
	session_start();

	if(isset($_SESSION['userID'])){
		header("location: index.php");
	}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">
	<title>Easy Research</title>

	<!-- Embedded CDN's -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

	<!-- External CSS -->
	<link rel="stylesheet" type="text/css" href="Assets/css/variables.css">
	<link rel="stylesheet" type="text/css" href="Assets/css/session.css">
</head>
<body>

	<!-- Nav -->
	<?php
		include_once("Assets/controls/parts/nav.php");
	?>

	<!-- Wave -->
	<div class="sessionWave">
		<svg id="wave" style="transform:rotate(180deg); transition: 0.3s" viewBox="0 0 1440 490" version="1.1" xmlns="http://www.w3.org/2000/svg"><defs><linearGradient id="sw-gradient-0" x1="0" x2="0" y1="1" y2="0"><stop stop-color="rgba(244.043, 156.467, 193.667, 1)" offset="0%"></stop><stop stop-color="rgba(255, 255, 255, 1)" offset="100%"></stop></linearGradient></defs><path style="transform:translate(0, 0px); opacity:1" fill="url(#sw-gradient-0)" d="M0,147L15,179.7C30,212,60,278,90,318.5C120,359,150,376,180,383.8C210,392,240,392,270,334.8C300,278,330,163,360,147C390,131,420,212,450,253.2C480,294,510,294,540,253.2C570,212,600,131,630,98C660,65,690,82,720,114.3C750,147,780,196,810,196C840,196,870,147,900,122.5C930,98,960,98,990,122.5C1020,147,1050,196,1080,245C1110,294,1140,343,1170,343C1200,343,1230,294,1260,294C1290,294,1320,343,1350,302.2C1380,261,1410,131,1440,138.8C1470,147,1500,294,1530,310.3C1560,327,1590,212,1620,179.7C1650,147,1680,196,1710,204.2C1740,212,1770,180,1800,163.3C1830,147,1860,147,1890,155.2C1920,163,1950,180,1980,179.7C2010,180,2040,163,2070,130.7C2100,98,2130,49,2145,24.5L2160,0L2160,490L2145,490C2130,490,2100,490,2070,490C2040,490,2010,490,1980,490C1950,490,1920,490,1890,490C1860,490,1830,490,1800,490C1770,490,1740,490,1710,490C1680,490,1650,490,1620,490C1590,490,1560,490,1530,490C1500,490,1470,490,1440,490C1410,490,1380,490,1350,490C1320,490,1290,490,1260,490C1230,490,1200,490,1170,490C1140,490,1110,490,1080,490C1050,490,1020,490,990,490C960,490,930,490,900,490C870,490,840,490,810,490C780,490,750,490,720,490C690,490,660,490,630,490C600,490,570,490,540,490C510,490,480,490,450,490C420,490,390,490,360,490C330,490,300,490,270,490C240,490,210,490,180,490C150,490,120,490,90,490C60,490,30,490,15,490L0,490Z"></path></svg>
	</div>


	<!-- Section -->
	<div class="container">

		<!-- Content -->
		<div class="rounded bg-pink col-12 col-sm-12 col-md-8 col-lg-6 col-xl-6 my-4 mx-auto">

			<!-- Switcher between login or register -->
			<div class="switchForm w-50 d-flex align-items-center justify-content-center mx-auto">
				<div class="loginSwitch w-50" id="transition-login">
					Login
					<div></div>
				</div>
				<div class="registerSwitch w-50" id="transition-register">
					Register
					<div></div>
				</div>
			</div>

			<!-- Session Forms -->
			<div class="overflow">
				<div class="sessionForm">
					<!-- login -->
					<div class="loginForm jumbotron bg-pink">
						<h4 class="text-left d-3 text-center text-white">Login</h4>
						<hr>
						<form>
							<div class="form-group">
								<!-- Username -->
								<div class="form-group">
									<label for="usernameL">Username: </label>
									<input type="text" class="customRounded form-control" name="usernameL" id="usernameL" placeholder="Username">
								</div>


								<!-- Password -->
								<div class="form-group">
									<label for="passL">Password: </label>
									<input type="password" class="customRounded form-control" name="passL" id="passL" placeholder="Password">
								</div>
							</div>

							<div class="form-group text-center">
								<input type="submit" class="customRounded form-submit btn text-white bg-grayishPink" id="loginSubmit" name="loginSubmit" value="Login">
							</div>
						</form>
					</div>

					<!-- register -->
					<div class="registerForm jumbotron bg-pink">
						<h4 class="text-left d-3 text-center text-white">Register</h4>
						<hr>
						<form>
							<div class="form-group">
								<!-- Full Name -->
								<div class="form-group">
									<label for="fullnameR">Full Name: </label>
									<input type="text" class="customRounded form-control" name="fullnameR" id="fullnameR" placeholder="Full Name (First (second) Initial. Surname)">
								</div>

								<!-- Username and Email -->
								<div class="form-group">
									<div class="row">
										<!-- Username -->
										<div class="col col-12 col-sm-12 col-md-12 col-lg-6 col-xl-6">
											<label for="usernameR">Username: </label>
											<input type="text" class="customRounded form-control" name="usernameR" id="usernameR" placeholder="Username">
										</div>

										<!-- Email -->
										<div class="col col-12 col-sm-12 col-md-12 col-lg-6 col-xl-6">
											<label for="emailR">E-mail: </label>
											<input type="text" class="customRounded form-control" name="emailR" id="emailR" placeholder="E-mail">
										</div>
									</div>
										
								</div>

								<!-- Password -->
								<div class="form-group">
									<label for="passR">Password: </label>
									<input type="password" class="customRounded form-control" name="passR" id="passR" placeholder="Password">
								</div>

								<!-- Re-type Password -->
								<div class="form-group">
									<label for="rePassR">Re-type Password: </label>
									<input type="password" class="customRounded form-control" name="rePassR" id="rePassR" placeholder="Re-type Password">
								</div>
							</div>

							<div class="form-group text-center">
								<input type="submit" class="customRounded form-submit btn text-white bg-grayishPink" id="registerSubmit" name="registerSubmit" value="Register">
							</div>
						</form>
					</div>
				</div>
			</div>
		</div>
	</div>


<!-- Embedded CDN's -->
<!-- JQuery -->
<script src="https://code.jquery.com/jquery-3.6.0.min.js" integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4=" crossorigin="anonymous"></script>
<!-- Bootstrap -->
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
<script src="//cdn.jsdelivr.net/npm/sweetalert2@11"></script>

<!-- External JS -->
<script type="text/javascript" src="Assets/js/sessionForm.js"></script>

</body>
</html>