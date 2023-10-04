---
marp: true
class : invert
theme : uncover
---

<style>
    @font-face {
        font-family: "Game";
        src: url('https://fonts.cdnfonts.com/css/game%27');
    }

    @keyframes rotate {
        to{ transform: rotate(360deg);}
    }

    .flower {
        width: 400px;
        position: absolute;
        top: -210px;
        animation: rotate 4s linear infinite;
    }

    .flower-l {
        left: -190px;
    }

    .flower-r {
        right: -190px;
    }

    h1 {
        font-size: 400%;
        text-decoration: underline;
        font-family: 'Game';
    }
    h2{
        font-size: 200%;
    }
    .type-desc {
        margin-bottom: 75px;
    }
    .col-2 {
        display: flex;
        justify-content: space-evenly;
    }

    .red {
        color: red;
    }
    .green {
        color: green;
    }
    .blue {
        color: blue;
    }
    .orange {
        color: orange;
    }

    td {
        border: 1px solid;
    }

    .poker {
        width: 55px;
        position: absolute;
        top: 52px;
        left: 383px;
        animation: rotate 3s linear infinite
    }
</style>

<img class="flower flower-l" src="https://i.imgur.com/hoO6CV4.png">
<img class="flower flower-r" src="https://i.imgur.com/hoO6CV4.png">
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
        <img src="https://i.imgur.com/XO01Rro.jpg" alt="placeholder">
    </div>
</div>

---

<h2>
User Story
</h2>
<div class="col-2">
    <ul>
        <li class="red">
            Tordre l'arbre
        </li>
        <li class="red">
            Lancer une graine
        </li>
        <li class="red">
            Planter un arbre
        </li>
        <li class="red">
            Tirer sur un ennemis
        </li>
        <li class="orange">
            Tuer des ennemis
        </li>
    </ul>
    <ul>
        <li class="green">
            Choisir une graine
        </li>
        <li class="green">
            Mettre pause au jeu
        </li>
        <li class="green">
            Reprendre le jeu
        </li>
        <li class="green">
            Aller au menu
        </li>
        <li class="green">
            Lancer une partie
        </li>
    </ul>
</div>
<legend>
    Degré d’importance => <span class="red"> O : !!!!!</span><span class="orange"> O : !!!!</span><span class="green"> O : !!!</span><span class="blue"> O : !!</span> O : !
</legend>

---

<h2>
    Roadmap
</h2>
<img src="https://i.imgur.com/7HaJ8ls.png">

---

<img class="poker" src="https://i.imgur.com/fTkCfuO.png">
<h2>
    Poker Planning
</h2>
<div>
    <table>
        <tbody>
            <tr>
              <td>Tirer sur un ennemis</td>
              <td>Tordre l'arbre</td>
              <td>Choisir une graine</td>
              <td>Aller au menu</td>
              <td>Mettre pause</td>
            </tr>
            <tr>
              <td></td>
              <td>Lancer une graine</td>
              <td>Tuer des ennemis</td>
              <td>Lancer une partie</td>
              <td>Reprendre le jeu</td>
            </tr>
            <tr>
                <td></td>
                <td></td>
                <td>Planter un Arbre</td>
                <td></td>
                <td></td>
            </tr>
            <tr>
                <td>8</td>
                <td>5</td>
                <td>2</td>
                <td>1</td>
                <td>1/2</td>
            </tr>
        </tbody>
    </table>
</div>

---

<h4>
    Merci de nous avoir écouté
</h4>

<footer>
    Tous droits réservés The Lab
</footer>
