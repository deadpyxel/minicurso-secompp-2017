<?php
    if ($_SESSION['user_logged_in'] !== true) {
        header('Location: /login.php');
    }

    function omg_important_private_functionality_here(){
    	echo "Pranked!";
    }

    omg_important_private_functionality_here();
?>