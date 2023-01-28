<?php
$msg = 
if ($_POST["message"]){
	mail("rv42088@gmail.com", "Mail",
	$_POST["Insert your message here"]. "From: rv42088@gmail.com");
}

?>