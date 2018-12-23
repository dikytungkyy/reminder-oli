
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

$query = "Select * FROM datamobil";
$hasil = mysqli_query($conn,$query);
$isi = mysqli_fetch_array($hasil,MYSQLI_NUM);

echo "<H1>$isi[0]<H1>";
echo "<hi>$isi[1]<hi>";

$conn->close();

$url=$_SERVER['REQUEST_URI'];
   header("Refresh: 10; URL=$url");



?>