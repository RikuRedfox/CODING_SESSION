// Function for Deleting a File
deleteFile = (id) => {
	Swal.fire({
	  	title: 'Are you sure you want to delete this file?',
	  	text: "You won't be able to revert this!",
	  	icon: 'warning',
	  	showCancelButton: true,
	  	confirmButtonColor: '#3085d6',
	  	cancelButtonColor: '#d33',
	  	confirmButtonText: 'Yes, Delete'
	}).then((result) => {
	  	if (result.isConfirmed) {
	  		$.ajax({
				type: "POST",
				url: "Assets/controls/actions/deleteFile.php",
				data: {
					ID: id
				},
				dataType: "json",
				cache: false,
				success: (data) =>{
					if (data.msg == 0){
						Swal.fire(
				      		'Deleted!',
				      		'Your file has been deleted.',
				      		'success'
				    	).then((res)=>{
				    		if (res.isConfirmed){
				    			location.href = "index.php";
				    		}
				    	});

		                
					}
					else if (data.msg == 1){
						Swal.fire(
				      		'Error!',
				      		'Somethings wrong. Try again later',
				      		'warning'
				    	);
					}
					else if (data.msg == 2){
						Swal.fire(
				      		'Error!',
				      		'Removing File Issue: Please try again later',
				      		'warning'
				    	);
					}
					else if (data.msg == 3){
						Swal.fire(
				      		'Error!',
				      		'Remove Failed, Please Try again later',
				      		'warning'
				    	);
					}
				}
			});
	    	
	  	}
	});
}

// Function for Reporting a File
reportFile = (id) => {
	(async () => {
		const inputOptions = new Promise((resolve) => {
			setTimeout(() => {
				resolve({
					'NSFW': '<span class="lineDesc">NSFW - Contains bad content</span>',
					'Inappropriate': '<span class="lineDesc">Inappropriate File - File isn\'t for academic purpose</span>',
					'Private Images': '<span class="lineDesc">Private Images - Contains private photo</span>',
					'Mocking File': '<span class="lineDesc">Mocking File - Made for mocking</span>'
				})
			}, 1000)
		});

		const { value: reason } = await Swal.fire({
			title: 'Report Reason',
			input: 'radio',
			customClass: {
			    input: 'my-radio'
			},
			inputOptions: inputOptions,
			inputValidator: (value) => {
				if (!value) {
					return 'Note: You need to choose one to report this file.'
				}
			}
		});

		if (reason) {
		  	$.ajax({
				type: "POST",
				url: "Assets/controls/actions/reportFile.php",
				data: {
					ID: id,
					Reason: reason
				},
				dataType: "json",
				cache: false,
				success: (data) =>{
					if (data.msg == "created"){
						Swal.fire(
				      		'Report',
				      		'The file is been reported.',
				      		'success'
				    	)
					}
					else if (data.msg == "updated"){
						Swal.fire(
				      		'Report',
				      		'The file is been reported.',
				      		'success'
				    	)
					}
					else if (data.msg == 1){
						Swal.fire(
				      		'Error!',
				      		'Report failed',
				      		'warning'
				    	);
					}
					else if (data.msg == 2){
						Swal.fire(
				      		'Error!',
				      		'No file found',
				      		'warning'
				    	);
					}
					else if (data.msg == 3){
						Swal.fire(
				      		'Error!',
				      		'Update Failed',
				      		'warning'
				    	);
					}
				}
			});
		}
	})()
}

// Function for Deleting a Report File
deleteReport = (id) => {
	Swal.fire({
	  	title: 'Are you sure you want to keep this Report?',
	  	text: "You won't be able to revert this!",
	  	icon: 'warning',
	  	showCancelButton: true,
	  	confirmButtonColor: '#3085d6',
	  	cancelButtonColor: '#d33',
	  	confirmButtonText: 'Yes, Keep'
	}).then((result) => {
	  	if (result.isConfirmed) {
	  		$.ajax({
				type: "POST",
				url: "Assets/controls/actions/deleteReport.php",
				data: {
					ID: id
				},
				dataType: "json",
				cache: false,
				success: (data) =>{
					if (data.msg == 0){
						Swal.fire(
				      		'Cleared!',
				      		'The file is been cleared.',
				      		'success'
				    	).then((res)=>{
				    		if (res.isConfirmed){
				    			location.href = "index.php";
				    		}
				    	});

		                
					}
					else if (data.msg == 1){
						Swal.fire(
				      		'Error!',
				      		'File Doesn\'t exist anymore',
				      		'warning'
				    	);
					}
					else if (data.msg == 2){
						Swal.fire(
				      		'Error!',
				      		'Clearing File Issue: Please try again later',
				      		'warning'
				    	);
					}
				}
			});
	    	
	  	}
	});
}

// Function for Viewing a File
viewFile = (id) => {
	$.ajax({
		type: "POST",
		url: "Assets/controls/actions/viewFile.php",
		data: {
			ID: id
		},
		dataType: "json",
		cache: false,
		success: (data) =>{
			if (data.msg == 1){
    			location.href = "viewFile.php";
			}
			else if (data.msg == 2){
				Swal.fire(
		      		'Error!',
		      		'No File found',
		      		'warning'
		    	);
			}
		}
	});
}

// Function for Removing a User
removeUser = (id) => {
	Swal.fire({
	  	title: 'Are you sure you want to delete this User?',
	  	text: "You won't be able to revert this!",
	  	icon: 'warning',
	  	showCancelButton: true,
	  	confirmButtonColor: '#3085d6',
	  	cancelButtonColor: '#d33',
	  	confirmButtonText: 'Yes, Delete'
	}).then((result) => {
	  	if (result.isConfirmed) {
	  		$.ajax({
				type: "POST",
				url: "Assets/controls/actions/removeUser.php",
				data: {
					ID: id
				},
				dataType: "json",
				cache: false,
				success: (data) =>{
					if (data.msg == 0){
						Swal.fire(
				      		'Deleted!',
				      		'The user has been deleted.',
				      		'success'
				    	).then((res)=>{
				    		if (res.isConfirmed){
				    			location.href = "index.php";
				    		}
				    	});
					}
					else if (data.msg == 1){
						Swal.fire(
				      		'Error!',
				      		'Delete Failed Query',
				      		'warning'
				    	);
					}
					else if (data.msg == 2){
						Swal.fire(
				      		'Error!',
				      		'No users found',
				      		'warning'
				    	);
					}
				}
			});
	    	
	  	}
	});
}

// Function for Downloading File
downloadFile = (file, name) => {
    $(".download").prop("disabled", true);

	Swal.fire({
	  	position: 'center',
	  	title: 'Downloading...',
	  	showConfirmButton: false,
	  	timer: 1500,
			timerProgressBar: true
	}).then((res)=>{
		$.ajax({
	        url: "Assets/Uploads/pdfFiles/"+file,
	        method: 'GET',
	        xhrFields: {
	            responseType: 'blob'
	        },
	        success: function (data) {
	    		$(".download").prop("disabled", false);
	            var a = document.createElement('a');
	            var url = window.URL.createObjectURL(data);
	            a.href = url;
	            a.download = name;
	            document.body.append(a);
	            a.click();
	            a.remove();
	            window.URL.revokeObjectURL(url);
	        }
	    });
	});
}