$(document).ready(()=>{
	/// Transition between login to register
	// Function 
	transitionForm = (spec) =>{
		switch(spec){
			case "login":
				sessionForm.css({
					"left" : "0%",
					"transition" : "all .5s ease-in-out"
				});

				loginSwitch.css(
					"width", "100%"
				);
				registerSwitch.css(
					"width", "0%"
				);
			break;

			case "register":
				sessionForm.css({
					"left" : "-100%",
					"transition" : "all .5s ease-in-out"
				});

				registerSwitch.css(
					"width", "100%"
				);
				loginSwitch.css(
					"width", "0%"
				);
			break;	

			default:
				// Login
			break;
		}
	}

	/// Initialize Variables
	// Session Forms
	let sessionForm = $(".sessionForm");
	let transitionLogin = $("#transition-login"); 
	let transitionRegister = $("#transition-register"); 

	// Switcher 
	let loginSwitch = $(".loginSwitch div");
	let registerSwitch = $(".registerSwitch div");

	transitionRegister.on("click", ()=>{
		transitionForm("register");
	});
	transitionLogin.on("click", ()=>{
		transitionForm("login");
	});

	// Profanity
	const badWords = ["fuck", "sex", "pakening", "bobo", "vovo", "tanga", "putangina", "putang ina", "puta", "tarantado", "siraulo", "tangina", "taena", 'gago', 'gaga', 'tite', 'pepe', 'dede', "d3d3", 'kantot', 'kantut', 'kantutan', 'kantotan', 'tit3', 'p3p3', 'titi', 'fvck', "inutil", "fucker", "tado", "fvk", "bitch", "deputa", "kingina"];



	/// Login Ajax ------------------------------------------------------------------------------------------------------
	var loginBtn = $("#loginSubmit");

	loginBtn.on("click", (e)=>{
		e.preventDefault();

		var username = $("[name=usernameL]").val();
		var password = $("[name=passL]").val();

		if (username == "" || password == ""){
			Swal.fire({
			  	position: 'center',
			  	title: 'Please fill all the fields.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if (!username.match(/^[a-zA-Z0-9]+([_-]?[a-zA-Z0-9])*$/)){
			Swal.fire({
			  	position: 'center',
			  	title: 'Invalid Username [a-z][A-Z][0-9][_-].',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if (password.length <= 7){
			Swal.fire({
			  	position: 'center',
			  	title: 'Passwords must be atleast 8 or more characters long.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else{
			$.ajax({
				type: "POST",
				url: "Assets/controls/login.php",
				data: {
					usernameL: username,
					passL: password
				},
				dataType: "json",
				cache: false,
				success: (data) =>{
					if (data.msg == 0){
						Swal.fire({
						  	position: 'center',
						  	title: 'Logged in.',
						  	showConfirmButton: false,
						  	timer: 1500,
			  				timerProgressBar: true
						}).then((res)=>{
			    			location.href = "index.php";
				    	});
					}
					else if (data.msg == 1){
						Swal.fire({
						  	position: 'center',
						  	title: 'Please fill all the fields.',
						  	showConfirmButton: false,
						  	timer: 1500,
			  				timerProgressBar: true
						})
					}
					else if (data.msg == 2){
						Swal.fire({
						  	position: 'center',
						  	title: 'Password must be atleast 8 or more characters.',
						  	showConfirmButton: false,
						  	timer: 1500,
			  				timerProgressBar: true
						})
					}
					else if (data.msg == 3){
						Swal.fire({
						  	position: 'center',
						  	title: 'Please fill all the fields.',
						  	showConfirmButton: false,
						  	timer: 1500,
			  				timerProgressBar: true
						})
					}
					else if (data.msg == 4){
						Swal.fire({
						  	position: 'center',
						  	title: 'Invalid Password.',
						  	showConfirmButton: false,
						  	timer: 1500,
			  				timerProgressBar: true
						})
					}
					else if (data.msg == 5){
						Swal.fire({
						  	position: 'center',
						  	title: 'Invalid Email or Password.',
						  	showConfirmButton: false,
						  	timer: 1500,
			  				timerProgressBar: true
						})
					}
				}
			});
		}
	});	

	/// Register Ajax ------------------------------------------------------------------------------------------------------
	var registerBtn = $("#registerSubmit");

	registerBtn.on("click", (e)=>{
		e.preventDefault();

		var fullname = $("[name=fullnameR]").val();
		var username = $("[name=usernameR]").val();
		var email = $("[name=emailR]").val();
		var password = $("[name=passR]").val();
		var confirmPassword = $("[name=rePassR]").val();

		if (username == "" || email == "" || password == "" || confirmPassword == "" || fullname == "" ||
			username == " " || email == " " || password == " " || confirmPassword == " " || fullname == " "){
			Swal.fire({
			  	position: 'center',
			  	title: 'Please fill all the fields.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if (!fullname.match(/^[A-Za-z\s]{1,}[\.]{0,1}[A-Za-z\s]{0,}$/)){
			Swal.fire({
			  	position: 'center',
			  	title: 'Enter a valid full name.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if ((username.trim().indexOf(' ') != -1) != false) {
			Swal.fire({
			  	position: 'center',
			  	title: 'Username cant be two or more words.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if (!username.match( /^[a-zA-Z0-9]+([_-]?[a-zA-Z0-9])*$/)){
			Swal.fire({
			  	position: 'center',
			  	title: 'Username Invalid. [a-z][A-Z][0-9][_-]',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if (username.length > 15 || username.length < 5){
			Swal.fire({
			  	position: 'center',
			  	title: 'Username only accepts at least 5 to 15 characters.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if (!email.match(/^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/)){
			Swal.fire({
			  	position: 'center',
			  	title: 'Invalid E-mail.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if (password.length <= 7 || confirmPassword.length <= 7){
			Swal.fire({
			  	position: 'center',
			  	title: 'Passwords must be at least 8 or more long.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else if (password != confirmPassword){
			Swal.fire({
			  	position: 'center',
			  	title: 'Password does not match.',
			  	showConfirmButton: false,
			  	timer: 1500,
  				timerProgressBar: true
			})
		}
		else{
			// If username contains Profanity words.
			badWords.every(elem =>{
				var lower = username.toLowerCase();

				if (lower.includes(elem)){
					Swal.fire({
					  	position: 'center',
					  	title: 'Username contains Bad Words.',
					  	showConfirmButton: false,
					  	timer: 1500,
		  				timerProgressBar: true
					});
					return false;
				}

				else{
					$.ajax({
						type: "POST",
						url: "Assets/controls/register.php",
						data: {
							rfullN: fullname,
							rUserN: username,
							rEmail: email,
							rPass: password,
							rRPass: confirmPassword
						},
						dataType: "json",
						cache: false,
						success: (data) =>{
							if (data.msg == 0){
								Swal.fire({
								  	position: 'center',
								  	title: 'Successfully Registered.',
								  	showConfirmButton: true
								}).then((res)=>{
					    			if (res.isConfirmed){
					    				sessionForm.css({
											"left" : "0%",
											"transition" : "all .5s ease-in-out"
										});

										loginSwitch.css(
											"width", "100%"
										);
										registerSwitch.css(
											"width", "0%"
										);
					    			}
						    	});
										
							}
							else if (data.msg == 1){
								alert("Fill up the fields");
							}
							else if (data.msg == 2){
								alert("Username does not accept 2 or more words");
							}
							else if (data.msg == 3){
								alert("Username only takes letters (a-z A-Z)");
							}
							else if (data.msg == 4){
								alert("Invalid E-mail");
							}
							else if (data.msg == 5){
								alert("Password must be atleast 8 or more characters length");
							}
							else if (data.msg == 6){
								alert("Password does not match");
							}
							else if (data.msg == 7){
								alert("Username contains Bad Words");
							}
							else if (data.msg == 8){
								alert("E-mail is already taken");
							}
							else if (data.msg == 9){
								alert("Something went wrong inserting values to database");
							}
							else if (data.msg == 10){
								alert("Username Can only contain 15 max characters.");
							}
						}
					});
				}
			});	
		}
	}) 
});