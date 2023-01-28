$(document).ready(() => {
	$("#photo").change(function () {
		 const file = this.files[0];
		 if (file) {
			 let reader = new FileReader();
			 reader.onload = function (event) {
				 $("#imgPreview")
				 .attr("src", event.target.result);
			 };
			 reader.readAsDataURL(file);
		 }
	 });
 });
 
