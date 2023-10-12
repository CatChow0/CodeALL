#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <get_data.h>

// ---------------------------------------- //
// Fonction pour choisir le premier pokemon //
// ---------------------------------------- //

int Player_pokemon_choice() {

    int player_pokemon_choice = 0;
    std::string Default_Pokemon_Name_1;
    std::string Default_Pokemon_Name_2;
    std::string Default_Pokemon_Name_3;

    // Ouvre le fichier Pokemon.txt et lit le Nom des 3 premier Pokemon //

    std::ifstream Pokemon_File;
    Pokemon_File.open("Pokemon.txt", std::ios::in);
    std::string name;
    std::getline(Pokemon_File, name);       // Récupère la premiere ligne (ID)
    std::getline(Pokemon_File, name, ' ');  // Récupère le nom de la variable et écrase les donnés de la première ligne
    std::getline(Pokemon_File, name);       // Récupère la valeur de la variable et écrase le nom de la variable
    Default_Pokemon_Name_1 = name;          // stocke le nom de la deuxieme variable dans la variable Default_Pokemon_Name_1

    for (int i = 0; i < 5; i++) {           // Saute 4 ligne pour récupérer le nom de la variable suviante comme l'écart entre les variable est constants
        std::getline(Pokemon_File, name); 
    };

    std::getline(Pokemon_File, name, ' ');
    std::getline(Pokemon_File, name);
    Default_Pokemon_Name_2 = name;

    for (int i = 0; i < 5; i++) {
        std::getline(Pokemon_File, name);
    };

    std::getline(Pokemon_File, name, ' ');
    std::getline(Pokemon_File, name);
    Default_Pokemon_Name_3 = name;
    Pokemon_File.close();

    // ------------------------------------------------ //
    // Propose au joueur de choisir son premier pokemon //
    // ------------------------------------------------ //

    int end_of_choice = 1;
    while (end_of_choice == 1) {
        std::cout << "Entre le numeros pour choisir ton pokemon de depart" << std::endl;
        std::cout << Default_Pokemon_Name_1 << " [1]," << Default_Pokemon_Name_2 << " [2],"<< Default_Pokemon_Name_3 << " [3]" << std::endl;
        std::cin >> player_pokemon_choice;

        switch (player_pokemon_choice)
        {
        case 1:
            std::cout << "Vous avez selectioner " << Default_Pokemon_Name_1 << " de type Feu "<< std::endl;
            break;
        case 2:
            std::cout << "Vous avez selectioner " << Default_Pokemon_Name_2 << " de type Eau" << std::endl;
            break;
        case 3:
            std::cout << "Vous avez selectioner " << Default_Pokemon_Name_3 << " de type Plante" << std::endl;
            break;
        default:
            break;
        };

        std::cout << "Valider le choix : " << std::endl << "Oui [0] || Non [1]" << std::endl;
        std::cin >> end_of_choice;

        // Empeche de choisir un pokemon qui n'existe pas

        if (end_of_choice > 1 || end_of_choice < 0) {
            end_of_choice = 0;
            std::cout << "Vous n'avez selectioner aucun des pokemons disponible" << std::endl;
        };
    };

    return player_pokemon_choice;
};

// ----------------------- //
// Choix du pokemon enemie //
// ----------------------- //

int Enemy_pokemon_choice(int Player_pokemon_Id) {
    int enemy_pokemon_choice = 0;

    switch (Player_pokemon_Id)
    {
    case 1: // Pokemon de type Feu pour le joueur
        enemy_pokemon_choice = 2;
        break;
    case 2: // Pokemon de type Eau pour le joueur
        enemy_pokemon_choice = 3;
        break;
    case 3: // Pokemon de type Plante pour le joueur
        enemy_pokemon_choice = 1;
        break;
    
    default:
        enemy_pokemon_choice = 1; // L'enemie l'Id 1 par defaut
        break;
    }

    return (enemy_pokemon_choice);
};

// ------ //
// Combat //
// ------ //

void fight(std::string Player_Pokemon_Name, int Player_Pokemon_Health, int Player_Pokemon_Attack, int Player_Pokemon_Defense, std::string Player_Pokemon_Type, std::string Enemy_Pokemon_Name, int Enemy_Pokemon_Health, int Enemy_Pokemon_Attack, int Enemy_Pokemon_Defense, std::string Enemy_Pokemon_Type) {

    int current_player_health = Player_Pokemon_Health;
    int current_enemy_health = Enemy_Pokemon_Health;

    int current_round = 0;
    bool end_of_battle = false;
    int action_choice;

    int type_bonus = 1;
    int potion = 3;

    while (end_of_battle == false) {
        
        if (current_round == 0) {
            std::cout << "Début du combat" << std::endl; // Début du combat
            std::cout << "Tour: " << current_round + 1 << std::endl;
        };

        // progressbar player_hp_bar(Player_Pokemon_Health); // Crée un barre de vie pour le joueur
        // player_hp_bar.set_todo_char(" ");
        // player_hp_bar.set_done_char("█");
        // player_hp_bar.set_opening_bracket_char("[");
        // player_hp_bar.set_closing_bracket_char("]");

        // progressbar enemy_hp_bar(Enemy_Pokemon_Health); // Crée un barre de vie pour l'enemie
        // enemy_hp_bar.set_todo_char(" ");
        // enemy_hp_bar.set_done_char("█");
        // enemy_hp_bar.set_opening_bracket_char("[");
        // enemy_hp_bar.set_closing_bracket_char("]");
        
        // std::cin >> current_player_health;

        // if (current_player_health <= 0) {
        //    end_of_battle = true;
        //    std::cout << "Vous avez perdu" << std::endl;
        // };

        // player_hp_bar.update();

        // Début de la phase d'attaque du joueur //

        std::cout << "Attaquer [1] | Objet [2]" << std::endl;
        std::cin >> action_choice;

        if (action_choice == 1) {

            type_bonus = type_modifier(Enemy_Pokemon_Type,Player_Pokemon_Type); // Ajuste le bonus de type pour l'attaque du joueur
            int current_player_attack = Player_Pokemon_Attack * type_bonus; // Calcul de l'attaque du joueur en fonction de son type
            int final_player_attack = current_player_attack - Enemy_Pokemon_Defense; // Calcul de l'attaque du joueur en fonction de la défense

            Enemy_Pokemon_Health = Enemy_Pokemon_Health - final_player_attack;
            
            std::cout << Player_Pokemon_Name << " attaque " << Enemy_Pokemon_Name << " avec " << final_player_attack << " points de dégats" << std::endl; // Attaque du joueur afficher dans la console

            if (Enemy_Pokemon_Health <= 0) { // verifie si l'enemie est mort
                end_of_battle = true;
                std::cout << "Vous avez gagner" << std::endl;
            } else {
                std::cout << Enemy_Pokemon_Name << " reste " << Enemy_Pokemon_Health << " points de vie" << std::endl;
                // enemy_hp_bar.update();
            };

            type_bonus = type_modifier(Enemy_Pokemon_Type,Player_Pokemon_Type); // Ajuste le bonus de type pour l'attaque de l'enemie
            int current_enemy_attack = Enemy_Pokemon_Attack * type_bonus; // Calcul de l'attaque de l'enemie en fonction de son type
            int final_enemy_attack = current_enemy_attack - Player_Pokemon_Defense; // Calcul de l'attaque de l'enemie en fonction de la défense
            
            Player_Pokemon_Health = Player_Pokemon_Health - final_enemy_attack;
            
            std::cout << Enemy_Pokemon_Name << " attaque " << Player_Pokemon_Name << " avec " << final_enemy_attack << " points de dégats" << std::endl; // Attaque de l'enemie afficher dans la console
            
            if (Player_Pokemon_Health <= 0) { // verifie si le joueur est mort
            
                end_of_battle = true;
                std::cout << "Vous avez perdu" << std::endl;
            } else {
                std::cout << Player_Pokemon_Name << " reste " << Player_Pokemon_Health << " points de vie" << std::endl;
                // player_hp_bar.update();
            };

            current_round++; // incremente le nombre de tour


        } else if ( action_choice == 2) {
            if (potion > 0) {
                std::cout << "Vous avez : " << potion << std::endl;
                Player_Pokemon_Health = Player_Pokemon_Health + 15;
                potion = potion - 1;
                current_round++; //incremente le nombre de tour
            } else {
                std::cout << "Vous n'avez plus de potion" << std::endl;
            };
            
        } else if ( action_choice > 2 || action_choice < 1) {
            std::cout << "Veuillez choisir un choix entre 1 et 2" << std::endl;
        };

    
    };

};

