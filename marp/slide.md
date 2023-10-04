---
marp: true
class : invert
theme : uncover
---

<style>
    @import url('https://fonts.cdnfonts.com/css/game%27');

    @font-face {
        font-family: "Game";
        src: url("fonts/Games.woff");
    }

    .flower {
        width: 30%;
        position: absolute;
        animation: rotate 4s linear infinite;
    }

    @keyframes rotate {
        to{
            transform: rotate(360deg);
        }
    }

    .flow-1 {
        top: -26%;
        left: -13%; 
    }

    .flow-2{
        top: -26%;
        right: -13%;
    }


    h1 {
        font-size: 500%;
        text-decoration: underline;
        font-family: 'Game', sans-serif;
    }
    h2{
        font-size: 250%;
    }
    .type-desc {
        margin-bottom: 75px;
    }
    .col-2 {
        display: flex;
        justify-content: space-evenly;
        margin-bottom: 40px;
    }
    legend {
        margin-bottom: 50px;
    }
    .user-st h5 {
        margin-bottom: 50px;
    }
    .user-st div legend {
        margin-top: 50px;
    }

    table{
        height: 10px;
    }
    td {
        font-size: 85%;
        border: 2px solid white;
    }

    .jeton-1, .jeton-2{
        width: 62px;
        position: absolute;
        top: 90px;
        left: 325px;
        animation: rotate 4s linear infinite;
    }


    .red {
        color: red;
    }
    .ora {
        color: orange;
    }
    .gre {
        color: green;
    }
    .blu {
        color: rgb(100, 100 ,255);
    }
</style>

<img class="flower flow-1" src="assets/flower.png">
<img class="flower flow-2" src="assets/flower.png">
<h1>
SEED WARS
</h1>

---

<h2>
SOMMAIRE
</h2>

- Description du jeu
- Fonctionalités
- User Story
- Roadmap
- Poker Planning

---

<h2>
Description
</h2>
<div class="type-desc">
    Type de jeu : Tower Defense (Twist Action)
</div>
<div class="col-2">
    <div class="col-l">
        <div class="gameplay">
            <ul>
                <li>Arbre
                <li>Catapulte
                <li>Graine
                <li>Tourelle
                <li>Ennemis
            </ul>
        </div>
    </div>
    <div class="col-r">
        <img src="assets/graines.jpg" alt="placeholder">
    </div>
</div>

---

<div class="user-st">
    <h2>
        User Story
    </h2>
    <h5>
        (Sprint n°1)
    </h5>
    <div class="col-2">
        <ul class="col-l">
            <li class="red">
                Tordre l'arbre
            </li>
            <li class="red">
                Tirer sur des ennemis
            </li>
            <li class="red">
                Lancer une graine
            </li>
            <li class="red">
                Planter un arbre
            </li>
            <li class="ora">
                Tuer des ennemis
            </li>
        </ul>
        <ul class="col-r">
            <li class="gre">
                Lancer une partie
            </li>
            <li class="gre">
                Choisir une Graine
            </li>
            <li class="gre">
                Mettre en pause
            </li>
            <li class="gre">
                Reprendre le jeu
            </li>
            <li class="gre">
                Aller au menu
            </li>
        </ul>
    </div>
    <div>
        <legend>
            Degré d’importance => <span class="red">O : !!!!!</span> <span class="ora">O : !!!!</span> <span class="gre">O : !!!</span> <span class="blu">O : !!</span> O : !
        </legend>
    </div>
</div>

---

<div class="road">
    <h2>
        Roadmap
    </h2>
    
</div>

---


<img class="jeton-1" src="assets/jeton-poker.png" alt="poker">
<img class="jeton-2" src="assets/jeton-poker.png" alt="poker">
<div class="poker">
    <h2>
        Poker Planning
    </h2>
    <table>
        <tbody>
            <tr>
                <td>Tirer sur un ennemi</td>
                <td>Tordre l'arbre</td>
                <td>Tuer un ennemi</td>
                <td>Lancer une partie</td>
                <td>Reprendre la partie</td>
            </tr>
            <tr>
                <td></td>
                <td>Lancer une graine</td>
                <td>Placer une tourelle</td>
                <td>Aller au menu</td>
                <td>Mettre pause</td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td>Choisir une graine</td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td>8pt</td>
                <td>5pt</td>
                <td>2pt</td>
                <td>1pt</td>
                <td>1/2pt</td>
            </tr>
        </tbody>
    </table>
</div>

---

### Tous droits réservés The Lab

