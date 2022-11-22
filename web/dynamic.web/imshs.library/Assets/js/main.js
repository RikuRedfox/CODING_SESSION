// File Upload Validation
var pdfFileUpload = $(".pdfFileUpload");
var pdfLabel = $(".pdf-file-label");

// Label Changer
pdfFileUpload.on('change', function(){ 
    if (pdfFileUpload[0].files.length === 1){
        pdfLabel.text(pdfFileUpload[0].files[0].name);
    }
    else{
        pdfLabel.text("Upload a PDF File");
    }
});

// Contributor Generator
var contributorCount = 1;
var addContributor = $("#addContributor");

addContributor.on("click", ()=>{
    contributorCount += 1;
    $(".contributor"+contributorCount).removeClass("d-none");

    if (contributorCount >= 8){
        addContributor.addClass("d-none");
    }
});


// Upload a File
$('#upload').submit(function(e) {
    // Prevent Default
    e.preventDefault();

    // Inputs
    var upTitle = $(".title").val();
    var upPass = $(".pass").val();

    // Contributors
    var upContributors = "";

    for (var i = 1; i <= contributorCount; i++){
        if (i == contributorCount){
            upContributors += $("#contributor"+i).val();
        } else{
            upContributors += $("#contributor"+i).val() + "*";
        }
    }

    // Profanity
    const badWords = ["fuck", "sex", "pakening", "bobo", "vovo", "tanga", "putangina", "putang ina", "puta", "tarantado", "siraulo", "tangina", "taena", 'gago', 'gaga', 'tite', 'pepe', 'dede', "d3d3", 'kantot', 'kantut', 'kantutan', 'kantotan', 'tit3', 'p3p3', 'titi', 'fvck', "inutil", "fucker", "tado", "fvk", "bitch", "deputa", "kingina"];
    var filename = $(".pdfFileUpload")[0].files[0];

    // Sanitize
    if (upTitle == "" || upTitle == " " || 
        upPass == "" || upPass == " " ||
        upContributors == "" || upContributors == " " ||
        pdfFileUpload[0].files.length === 0)
    {
        Swal.fire({
            position: 'center',
            title: 'Please fill all the fields.',
            showConfirmButton: false,
            timer: 1500,
            timerProgressBar: true
        })
    }
    else if (filename.name.split('.').pop() != "pdf" && !filename.name.split('.').pop() != "PDF"){
        Swal.fire({
            position: 'center',
            title: 'The file is not a PDF document.',
            showConfirmButton: false,
            timer: 1500,
            timerProgressBar: true
        })
    }
    else{

        var textTitle = upTitle;
        var textFormat = textTitle.toLowerCase();
        var allowRun = true;

        badWords.forEach(elem =>{
            if (textFormat.includes(elem)) {
                allowRun = false;
                return;
            }
        });

        if (allowRun){
            // File
            var files = new FormData();
            files.append('File', $('.pdfFileUpload')[0].files[0]);
            files.append('Title', upTitle);
            files.append('Contributors', upContributors);
            files.append('Password', upPass);

            $("#pdfUpload").prop("disabled", true);

            $.ajax({             
                type: "POST",
                url: 'Assets/controls/upload.php',
                data: files,
                dataType: 'json', 
                processData: false,
                contentType: false,
                cache: false,
                enctype: 'multipart/form-data',

                success: (data) =>{
                    $("#pdfUpload").prop("disabled", false);

                    if(data.msg == 0){
                        Swal.fire({
                            position: 'center',
                            title: 'Uploaded Successfully.',
                            showConfirmButton: true
                        }).then((res)=>{
                            if (res.isConfirmed){
                                location.href = "index.php";
                            }
                        });
                    }
                    else if (data.msg == 1){
                        Swal.fire({
                            position: 'center',
                            title: 'Please fill up all the fields.',
                            showConfirmButton: false,
                            timer: 1500,
                            timerProgressBar: true
                        })
                    }
                    else if (data.msg == 2){
                        Swal.fire({
                            position: 'center',
                            title: 'The file is not a PDF document.',
                            showConfirmButton: false,
                            timer: 1500,
                            timerProgressBar: true
                        })
                    }
                    else if (data.msg == 3){
                        Swal.fire({
                            position: 'center',
                            title: 'Upload Failed.',
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
                            title: 'Query Error.',
                            showConfirmButton: false,
                            timer: 1500,
                            timerProgressBar: true
                        })
                    }
                }
             });
        }
        else{
            Swal.fire({
                position: 'center',
                title: 'Title Contains Bad Words.',
                showConfirmButton: false,
                timer: 1500,
                timerProgressBar: true
            })
        }
    }
});

$(".intro").delay(3000).fadeOut(1000);