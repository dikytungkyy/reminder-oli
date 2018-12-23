<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "coba";

$conn= new mysqli($servername, $username, $password, $dbname);
if ($conn -> connect_error)
{
die("connection failed:".$connection->connect_error);
}
$KM=$_GET["km"];

$sql = "UPDATE datamobil SET KM_Mobil = $KM WHERE Id_Mobil = 1" ;

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}

$conn->close();
?>