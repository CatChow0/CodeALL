#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
// #include <include/pokemon_list.h>
// #include <include/game.h>
// #include <include/get_data.h>



// ------------------ //
// Class des pokemons
// ------------------ //

class Character {

    public: 

        char name[20];
        int health;
        int base_attack;
        int base_defense;
        int pokemon_id;
        char type[20];

};

// ---------------------------------------------------------------- //
// Creation d'un pokemon et stock c'est information dans un fichier //
// ---------------------------------------------------------------- //

void Create_Pokemon() {

    Character Create_Pokemon;

    // Demande les informations du pokemon
    std::cout << "Entrez l'id du Pokemon : ";
    std::cin >> Create_Pokemon.pokemon_id;
    std::cout << "Entrez le nom du Pokemon : ";
    std::cin >> Create_Pokemon.name;
    std::cout << "Entrez la vie du Pokemon : ";
    std::cin >> Create_Pokemon.health;
    std::cout << "Entrez l'attaque de base du Pokemon : ";
    std::cin >> Create_Pokemon.base_attack;
    std::cout << "Entrez la defense de base du Pokemon : ";
    std::cin >> Create_Pokemon.base_defense;
    std::cout << "Entrez le type du Pokemon : ";
    std::cin >> Create_Pokemon.type;

    // Affiche les informations du pokemon creé

    std::cout << "Pokemon cree avec succes!" << std::endl;
    std::cout << "Id du Pokemon : " << Create_Pokemon.pokemon_id << std::endl;
    std::cout << "Nom du Pokemon : " << Create_Pokemon.name << std::endl;
    std::cout << "Vie du Pokemon : " << Create_Pokemon.health << std::endl;
    std::cout << "Base d'attaque du Pokemon : " << Create_Pokemon.base_attack << std::endl;
    std::cout << "Base de defense du Pokemon : " << Create_Pokemon.base_defense << std::endl;
    std::cout << "Type du Pokemon : " << Create_Pokemon.type << std::endl;

    // Ouvre ou Crée un fichier pour stocker les pokemons

    std::ofstream Create_Pokemon_File;
    Create_Pokemon_File.open("Pokemon.txt", std::ios::out | std::ios::app);
    Create_Pokemon_File << "Id: " <<Create_Pokemon.pokemon_id << std::endl;
    Create_Pokemon_File << "Nom: " <<Create_Pokemon.name << std::endl;
    Create_Pokemon_File << "Health: " <<Create_Pokemon.health << std::endl;
    Create_Pokemon_File << "Attack: " <<Create_Pokemon.base_attack << std::endl;
    Create_Pokemon_File << "Defense: " <<Create_Pokemon.base_defense << std::endl;
    Create_Pokemon_File << "Type: " <<Create_Pokemon.type << std::endl;
    Create_Pokemon_File.close();

};

// ------------------ //
// list les pokemons //
// ------------------ //

void List_Pokemon() {

    // Ouvre ou Crée un fichier pour stocker les pokemons

    std::ifstream List_Pokemon_File;
    List_Pokemon_File.open("Pokemon.txt", std::ios::in);

    if (List_Pokemon_File.is_open()) {
        std::cout << "Liste des pokemons" << std::endl;
        while (!List_Pokemon_File.eof()) {
            std::string line;
            std::getline(List_Pokemon_File, line);
            std::cout << line << std::endl;
        }
        List_Pokemon_File.close();
    } else {
        std::cout << "Impossible de lire le fichier" << std::endl;
    }

};

// ------------------------------------- //
// Récupère le nom du pokemon par son ID //
// ------------------------------------- //

std::string Current_Pokemon_Name(int Player_pokemon_Id) {

    std::string Id = "Id: ";
    std::string Player_Pokemon_Id_String = std::to_string(Player_pokemon_Id);
    std::string Id_to_find = Id + Player_Pokemon_Id_String;

    std::ifstream Pokemon_File;
    Pokemon_File.open("Pokemon.txt", std::ios::in);

    std::string Pokemon_Name;
    while (std::getline(Pokemon_File,Pokemon_Name)) {
        if (Pokemon_Name.find(Id_to_find) != std::string::npos) {
            break;
        };
    };
    std::getline(Pokemon_File,Pokemon_Name, ' ');
    std::getline(Pokemon_File,Pokemon_Name);
    Pokemon_File.close();

    return Pokemon_Name;
};

// ----------------------------- //
// Récupère les stats du pokemon //
// ----------------------------- //

int stats(int Pokemon_ID, int stats_ligne) { // stats_ligne = ligne de la stats par rapport a l'ID du pokemon

    std::string Id = "Id: ";
    std::string Pokemon_Id_String = std::to_string(Pokemon_ID);
    std::string Id_to_find = Id + Pokemon_Id_String;

    std::ifstream Pokemon_File;
    Pokemon_File.open("Pokemon.txt", std::ios::in);

    std::string Pokemon_Stats;
    while (std::getline(Pokemon_File,Pokemon_Stats)) {
        if (Pokemon_Stats.find(Id_to_find)!= std::string::npos) {
            break;
        };
    };
    for (int i = 0; i < stats_ligne; i++) { // Vas à la ligne de la stats voulue
        std::getline(Pokemon_File,Pokemon_Stats);

    };
    std::getline(Pokemon_File,Pokemon_Stats,' ');
    std::getline(Pokemon_File,Pokemon_Stats);
    Pokemon_File.close();

    int Res_Pokemon_Stats = std::stoi(Pokemon_Stats);

    return Res_Pokemon_Stats;
};

// -------------------------- //
// Récupère le type du pokemon//
// -------------------------- //

std::string current_pokemon_type(int Pokemon_ID) {

    std::string Id = "Id: ";
    std::string Pokemon_Id_String = std::to_string(Pokemon_ID); 
    std::string Id_to_find = Id + Pokemon_Id_String;
    std::ifstream Pokemon_File;
    Pokemon_File.open("Pokemon.txt", std::ios::in);

    std::string Pokemon_Type;
    while (std::getline(Pokemon_File,Pokemon_Type)) { // Va à la ligne de L'ID carrespondant
        if (Pokemon_Type.find(Id_to_find)!= std::string::npos) {
            break;
        };
    };

    for (int i = 0; i < 4; i++) { // Vas à la ligne du type voulue
        std::getline(Pokemon_File,Pokemon_Type);
    
    };
    std::getline(Pokemon_File,Pokemon_Type, ' ');
    std::getline(Pokemon_File,Pokemon_Type);
    Pokemon_File.close();

    return Pokemon_Type;
};

// ------------------------------------------------------ //
// Applique les bonus malus de dégàts en fonction du type //
// ------------------------------------------------------ //

float type_modifier(std::string Attack_Pokemon_Type, std::string Target_Pokemon_Type) {

    float res;
    
    if (Attack_Pokemon_Type == Target_Pokemon_Type) {
        res = 1;
    } else if ( Attack_Pokemon_Type == "Eau" && Target_Pokemon_Type == "Plante") {
        res = 0.75;
    } else if ( Attack_Pokemon_Type == "Eau" && Target_Pokemon_Type == "Feu") {
        res = 1.25;
    } else if ( Attack_Pokemon_Type == "Plante" && Target_Pokemon_Type == "Eau") {
        res = 1.25;
    } else if ( Attack_Pokemon_Type == "Plante" && Target_Pokemon_Type == "Feu") {
        res = 0.75;
    } else if ( Attack_Pokemon_Type == "Feu" && Target_Pokemon_Type == "Eau") {
        res = 0.75;
    } else if ( Attack_Pokemon_Type == "Feu" && Target_Pokemon_Type == "Plante") {
        res = 1.25;
    };

    return res;
};

// ---------------------------- //
// Renomme le Pokemon du joueur //
// ---------------------------- //

std::string rename_Pokemon(std::string Player_Pokemon) {
    int rename_choice = 0;
    int valide_choice = 0;
    std::string res;

    while (rename_choice == 0) {

        std::cout << "Voulez-vous renommer votre pokemon de depart?" << std::endl << "Oui [0] || Non [1]" << std::endl;
        std::cin >> rename_choice;

        // Empeche de choisir une option qui n'existe pas
        if (rename_choice > 1 || rename_choice < 0) {
            rename_choice = 0;
            std::cout << "Vous n'avez selectioner aucune des options disponible" << std::endl;
        } else if (rename_choice == 1) { // Sort de la boucle si le joueur ne veut pas renommer son pokemon
            res = Player_Pokemon;
        } else {
            std::cout << "Entre le nouveau nom du pokemon" << std::endl;
            std::cin >> Player_Pokemon;
            std::cout << "Valider le choix : \"" << Player_Pokemon << "\" " << std::endl << "Oui [0] || Non [1]" << std::endl;
            std::cin >> valide_choice;
            if (valide_choice == 0) {
                res = Player_Pokemon;
                rename_choice = 1;
            };
            
        };      
    };

    return res;
};

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

    std::random_device random;
    std::mt19937 rng(random());
    std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7);

    while (end_of_battle == false) {
        
        if (current_round == 0) {
            std::cout << "Debut du combat" << std::endl; // Début du combat
            std::cout << "Tour: " << current_round + 1 << std::endl;
        } else {
            std::cout << "Tour : " << current_round << std::endl;
        };

        // progressbar player_hp_bar(current_player_health); // Crée un barre de vie pour le joueur
        // player_hp_bar.set_todo_char(" ");
        // player_hp_bar.set_done_char("█");
        // player_hp_bar.set_opening_bracket_char("[");
        // player_hp_bar.set_closing_bracket_char("]");
        // player_hp_bar.update();

        // progressbar enemy_hp_bar(current_enemy_health); // Crée un barre de vie pour l'enemie
        // enemy_hp_bar.set_todo_char(" ");
        // enemy_hp_bar.set_done_char("█");
        // enemy_hp_bar.set_opening_bracket_char("[");
        // enemy_hp_bar.set_closing_bracket_char("]");
        // enemy_hp_bar.update();
        
        // std::cin >> current_player_health;

        if (current_player_health <= 0) {
            end_of_battle = true;
            std::cout << "Vous avez perdu" << std::endl;
            break;
        };

        // Début de la phase d'attaque du joueur //

        std::cout << "Attaquer [1] | Objet [2]" << std::endl;
        std::cin >> action_choice;

        

        if (action_choice == 1) {

            type_bonus = type_modifier(Enemy_Pokemon_Type,Player_Pokemon_Type); // Ajuste le bonus de type pour l'attaque du joueur
            int current_player_attack = dist7(rng) + (Player_Pokemon_Attack * type_bonus); // Calcul de l'attaque du joueur en fonction de son type
            std::cout << "Attaque base du joueur : " << Player_Pokemon_Attack << std::endl;
            std::cout << "Attaque du joueur : " << current_player_attack << std::endl;
            std::cout << "Attaque du joueur avec le bonus de type : " << current_player_attack * type_bonus << std::endl;
            std::cout << "Valeur de la défense du joueur : " << Enemy_Pokemon_Defense << std::endl;
            int final_player_attack = current_player_attack - Enemy_Pokemon_Defense; // Calcul de l'attaque du joueur en fonction de la défense

            current_enemy_health = current_enemy_health - abs(final_player_attack); // Valleur absolue du nombre de dégats
            
            std::cout << Player_Pokemon_Name << " attaque " << Enemy_Pokemon_Name << " avec " << abs(final_player_attack) << " points de degats" << std::endl; // Attaque du joueur afficher dans la console

            if (current_enemy_health <= 0) { // verifie si l'enemie est mort
                end_of_battle = true;
                std::cout << "Vous avez gagner" << std::endl;
            } else {
                std::cout << Enemy_Pokemon_Name << " reste " << current_enemy_health << " points de vie" << std::endl;
            };

            type_bonus = type_modifier(Enemy_Pokemon_Type,Player_Pokemon_Type); // Ajuste le bonus de type pour l'attaque de l'enemie
            int current_enemy_attack = dist7(rng) + (Enemy_Pokemon_Attack * type_bonus); // Calcul de l'attaque de l'enemie en fonction de son type
            int final_enemy_attack = current_enemy_attack - Player_Pokemon_Defense; // Calcul de l'attaque de l'enemie en fonction de la défense
            
            current_player_health = current_player_health - abs(final_enemy_attack); // Valeur absolue du nombre de dégats
            
            std::cout << Enemy_Pokemon_Name << " attaque " << Player_Pokemon_Name << " avec " << abs(final_enemy_attack) << " points de degats" << std::endl; // Attaque de l'enemie afficher dans la console
            
            if (Player_Pokemon_Health <= 0) { // verifie si le joueur est mort
            
                end_of_battle = true;
                std::cout << "Vous avez perdu" << std::endl;
            } else {
                std::cout << Player_Pokemon_Name << " reste " << current_player_health << " points de vie" << std::endl;
                // player_hp_bar.update();
                current_round++; // incremente le nombre de tour
            };

            


        } else if ( action_choice == 2) {
            if (potion > 0) {
                std::cout << "Vous avez : " << potion - 1<< "potion" << std::endl;
                current_player_health = current_player_health + 15;
                potion--;
                type_bonus = type_modifier(Enemy_Pokemon_Type,Player_Pokemon_Type); // Ajuste le bonus de type pour l'attaque de l'enemie
                int current_enemy_attack = dist7(rng) + (Enemy_Pokemon_Attack * type_bonus); // Calcul de l'attaque de l'enemie en fonction de son type
                int final_enemy_attack = current_enemy_attack - Player_Pokemon_Defense; // Calcul de l'attaque de l'enemie en fonction de la défense
            
                current_player_health = current_player_health - final_enemy_attack;
            
                std::cout << Enemy_Pokemon_Name << " attaque " << Player_Pokemon_Name << " avec " << final_enemy_attack << " points de degats" << std::endl; // Attaque de l'enemie afficher dans la console

                current_round++; //incremente le nombre de tour
            } else {
                std::cout << "Vous n'avez plus de potion" << std::endl;
            };
            
        } else if ( action_choice > 2 || action_choice < 1) {
            std::cout << "Veuillez choisir un choix entre 1 et 2" << std::endl;
        };

    
    };

};

// ------------------- //
// Fonction principale //
// ------------------- //

int main() {

    std::cout << "Bonjour jeune margoulin" << std::endl;

    int Player_Starter_Id = Player_pokemon_choice();

    int Enemy_Starter_Id = Enemy_pokemon_choice(Player_Starter_Id);

    std::string Player_Starter_Name = Current_Pokemon_Name(Player_Starter_Id); // Récupère le nom du pokemon du joueur
    Player_Starter_Name = rename_Pokemon(Player_Starter_Name); // Renomme le pokemon du joueur
    std::cout << "Player Pokemon Name: " << Player_Starter_Name << std::endl;
    int Player_Starter_Health = stats(Player_Starter_Id, 1); // Récupère la vie
    std::cout << "Player Pokemon Health: " << Player_Starter_Health << std::endl;
    int Player_Starter_Attack = stats(Player_Starter_Id, 2); // Récupère l'attaque
    std::cout << "Player Pokemon Attack: " << Player_Starter_Attack << std::endl;
    int Player_Starter_Defense = stats(Player_Starter_Id, 3); // Récupère la defense
    std::cout << "Player Pokemon Defense: " << Player_Starter_Defense << std::endl;
    std::string Player_Pokemon_Type = current_pokemon_type(Player_Starter_Id); // Récupère le type
    std::cout << "Player Pokemon Type: " << Player_Pokemon_Type << std::endl;

    std::string Enemy_starter_Name = Current_Pokemon_Name(Enemy_Starter_Id); // Récupère le nom du pokemon de l'enemie
    std::cout << "Enemy Pokemon Name: " << Enemy_starter_Name << std::endl;
    int Enemy_Starter_Health = stats(Enemy_Starter_Id, 1); // Récupère la vie
    std::cout << "Enemy Pokemon Health: " << Enemy_Starter_Health << std::endl;
    int Enemy_Starter_Attack = stats(Enemy_Starter_Id, 2); // Récupère la attaque
    std::cout << "Enemy Pokemon Attack: " << Enemy_Starter_Attack << std::endl;
    int Enemy_Starter_Defense = stats(Enemy_Starter_Id, 3); // Récupère la defense
    std::cout << "Enemy Pokemon Defense: " << Enemy_Starter_Defense << std::endl;
    std::string Enemy_Pokemon_Type = current_pokemon_type(Enemy_Starter_Id); // Récupère le type
    std::cout << "Enemy Pokemon Type: " << Enemy_Pokemon_Type << std::endl;

    fight(Player_Starter_Name, Player_Starter_Health, Player_Starter_Attack, Player_Starter_Defense, Player_Pokemon_Type, Enemy_starter_Name, Enemy_Starter_Health, Enemy_Starter_Attack, Enemy_Starter_Defense, Enemy_Pokemon_Type); // Lance le combat


    // Permet d'ajouter un nouveau pokemon dans le fichier Pokemon.txt
    // Create_Pokemon(); 

    return 0;
}