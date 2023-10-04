<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>CV</title>
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <!-- Animated Wallpaper -->
        <div id="blur" class="area">
            <ul class="circles">
                <li></li>
                <li></li>
                <li></li>
                <li></li>
                <li></li>
                <li></li>
                <li></li>
                <li></li>
                <li></li>
                <li></li>
            </ul>
            <header class="spikes">
                <h1 id="myname" class="">ANTHONY RIVAS</h1>
            </header>
            <main class="foreground">
                <!-- Top Band -->
                <section class="info">
                    <form class="base">
                        <img src="asset/ProfilPic.jpg" alt="ProfilPic">
                        <div>
                            <h2 class="whoami">QUI SUIS-JE?</h2>
                            <h3>18 ANS</h3>
                            <h3>ÎLE DE FRANCE</h3>
                            <h3>DÉVELOPPEUR WEB</h3>
                            <h3>GAME DÉVELOPPEUR</h3>
                        </div>
                    </form>
                </section>
                <!-- Button section -->
                <section class="competence">
                    <form class="base">
                        <div class="prog">
                            <label class="progra">
                                <h3>HTML-CSS ET JAVASCRIPT</h3>
                                <div>
                                    <button type="button" class="custom-btn btn-pimp" onclick="show()">
                                        Pac Man
                                    </button>
                                </div>
                            </label>
                            <label class="lang">
                                <h3>JAPONAIS ET ANGLAIS</h3>
                                <div>
                                    <button type="button" class="custom-btn btn-pimp2">
                                        Read More
                                    </button>
                                </div>

                            </label>
                        </div>
                    </form>
                </section>
                <!-- ShowCase -->
                <section id="showcase" class="showcase"> <!--Add class active-->
                    <div id="close-showcase" class="close-showcase" onclick="show()">
                        <h2>X</h2>
                    </div>
                    <div class="space-showcase">
                        <!-- Phase 1 -->
                        <div id="starting" class="start" onclick="start()"> <!--Add class phase2-->
                            <span style="--i:1">S</span>
                            <span style="--i:2">T</span>
                            <span style="--i:3">A</span>
                            <span style="--i:4">R</span>
                            <span style="--i:5">T</span>
                        </div>
                        <!-- Phase 2 -->
                        <div id="pac" class="pre"> <!--Add class phase2-->
                            <div class="pacman">
                            </div>

                        </div>

                    </div>

                </section>
                <!-- Lang Animation & info -->
                <!-- Click on button = black screen whith japanesse neon red text slowly show off
                and more you scroll more info you got in japanesse into english into french-->
                <section id="langinfo" class="langinfo"> <!--Add tada-->
                    <div class="scroll-d">
                        <h2>Scroll  Down</h2>
                    </div>


                </section>
                <!-- Contact -->
                <section id="contoff" class="contact">
                    <div class="contband">
                        <h2 class="Contquest">Une Question ? <span><a href="admin.php">.</a></span></h2>
                    </div>
                    <div id="off" class="off" onclick="contactoff()">
                        <h2 id="onleft" class="onleft">»<br>»</h2>
                        <h2 id="onright" class="onright onleft">«<br>«</h2>
                    </div>

                    <?php  
                    //Conexion a la data base
                    $pdo = new PDO('mysql:host=localhost;dbname=catchowcontact', 'root', 'root', array(PDO::ATTR_ERRMODE => PDO::ERRMODE_WARNING, PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'));
                    if ($_POST) {
                        $pdo->exec("INSERT INTO contact (prenom, nom, email, tel) VALUES ('$_POST[prenom]', '$_POST[nom]', '$_POST[email]', '$_POST[tel]')");
                    }
                    ?>
                    
                    <!-- Formulaire de contact -->
                    <form method="POST" action="" class="Infotopush">
                        <div class="infopush">
                            <div class="nameinfo">
                                <div class="prenom">
                                    <input type="text" name="prenom" placeholder="prenom"/>
                                </div>
                                <div class="nom">
                                    <input type="text" name="nom" placeholder="nom"/>
                                </div>
                            </div>
                            <div class="sendinfo">
                                <div class="email">
                                    <input type="email" name="email" placeholder="email"/>
                                </div>
                                <div class="tel">
                                    <input type="tel" name="tel" placeholder="tel"/>
                                </div>
                            </div>
                            <div class="submit">
                                <input type="submit" value="Envoyer" />
                            </div>
                           
                            
                            
                        </div>
                    </form>

                    


                </section>
                
            </main>
        </div>
    
    <script src="index.js"></script>
    </body>
</html>