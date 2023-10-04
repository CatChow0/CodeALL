<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>AdminPanel</title>
        <link rel="stylesheet" href="style.css">
    </head>
    <body class="admin-body" >

    <?php
    // Connexion avec data base
    $user='root';
    $pass='root';
    $db='catchowcontact';
    $db=new mysqli('localhost',$user,$pass,$db) or die("fail to connect");

    // Selectione la table
    $sql="select * from contact";
    $result=mysqli_query($db,$sql) or die("bad query");


    //Affichage en tableau
    echo "<table border='1'>";
    echo "<tr><td>id</td><td>prenom</td><td>nom</td><td>email</td><td>tel</td></tr>\n";


    while($row=mysqli_fetch_assoc($result)) {
        echo"<tr><td>{$row['id']}</td><td>{$row['prenom']}</td><td>{$row['nom']}</td><td>{$row['email']}</td><td>{$row['tel']} <br>";
    }
    echo "</table>";
    ?>

    

    <script src="index.js"></script>
    </body>
</html>