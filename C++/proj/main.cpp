#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

// ------------------ //
// Class des pokemons //
// ------------------ //

class Character {

    public: 

        char name[20];
        int health;
        int base_attack;
        int base_defense;
        int pokemon_id;
    
    class Fire_type {
        public:
            bool is_fire = true;
            char type_fire[20] = "Feu";
    };
    class Water_type {
        public:
            bool is_water = true;
            char type_Water[20] = "Eau";
    };
    class Plant_type {
        public:
            bool is_plant = true;
            char type_plant[20] = "Plante";
    };

};

// ---------------------------------------------------------------- //
// Creation d'un pokemon et stock c'est information dans un fichier //
// ---------------------------------------------------------------- //

void Create_Pokemon() {

    Character Create_Pokemon;

    // Demande les informations du pokemon

    std::cout << "Entrez le nom du Pokemon : ";
    std::cin >> Create_Pokemon.name;
    std::cout << "Entrez la vie du Pokemon : ";
    std::cin >> Create_Pokemon.health;
    std::cout << "Entrez la base d'attaque du Pokemon : ";
    std::cin >> Create_Pokemon.base_attack;
    std::cout << "Entrez la base de defense du Pokemon : ";
    std::cin >> Create_Pokemon.base_defense;
    std::cout << "Entrez l'id du Pokemon : ";
    std::cin >> Create_Pokemon.pokemon_id;

    // Affiche les informations du pokemon creé

    std::cout << "Pokemon cree avec succes!" << std::endl;
    std::cout << "Nom du Pokemon : " << Create_Pokemon.name << std::endl;
    std::cout << "Vie du Pokemon : " << Create_Pokemon.health << std::endl;
    std::cout << "Base d'attaque du Pokemon : " << Create_Pokemon.base_attack << std::endl;
    std::cout << "Base de defense du Pokemon : " << Create_Pokemon.base_defense << std::endl;
    std::cout << "Id du Pokemon : " << Create_Pokemon.pokemon_id << std::endl;

    // Ouvre ou Crée un fichier pour stocker les pokemons

    std::ofstream Create_Pokemon_File;
    Create_Pokemon_File.open("Pokemon.txt", std::ios::out | std::ios::app);
    Create_Pokemon_File << "Nom: " <<Create_Pokemon.name << std::endl;
    Create_Pokemon_File << "Health: " <<Create_Pokemon.health << std::endl;
    Create_Pokemon_File << "Attack: " <<Create_Pokemon.base_attack << std::endl;
    Create_Pokemon_File << "Defense: " <<Create_Pokemon.base_defense << std::endl;
    Create_Pokemon_File << "Id: " <<Create_Pokemon.pokemon_id << std::endl;
    Create_Pokemon_File.close();

};

// ---------------------------------------- //
// Fonction pour choisir le premier pokemon //
// ---------------------------------------- //

int pokemon_choice() {

    int player_pokemon_id = 0;
    char Default_Pokemon_Name_1[20];
    char Default_Pokemon_Name_2[20];
    char Default_Pokemon_Name_3[20];


    // Boucle qui permet de choisir le premier pokemon

    // Ouvre le fichier Pokemon.txt et lit le Nom des 3 premier Pokemon //

    std::ifstream Pokemon_File;
    Pokemon_File.open("Pokemon.txt", std::ios::in);
    std::string line;
    std::getline(Pokemon_File, line) >> Default_Pokemon_Name_1;
    std::getline(Pokemon_File, line) >> Default_Pokemon_Name_2;
    std::getline(Pokemon_File, line) >> Default_Pokemon_Name_3;
    Pokemon_File.close();

    // 

    // Affiche les noms des 3 premiers Pokemon //
    std::cout << "Nom du Pokemon 1 : " << Default_Pokemon_Name_1 << std::endl;
    std::cout << "Nom du Pokemon 2 : " << Default_Pokemon_Name_2 << std::endl;
    std::cout << "Nom du Pokemon 3 : " << Default_Pokemon_Name_3 << std::endl;

    int end_of_choice = 0;
    while (end_of_choice == 0) {
        std::cout << "Entre le numeros pour choisir ton pokemon de depart" << std::endl;
        std::cout << Default_Pokemon_Name_1 << " [1]," << Default_Pokemon_Name_2 << " [2],"<< Default_Pokemon_Name_3 << " [3]" << std::endl;
        std::cin >> player_pokemon_id;

        switch (player_pokemon_id)
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
        }

        std::cout << "Valider le choix : " << std::endl << "Oui [0] || Non [1]" << std::endl;
        std::cin >> end_of_choice;

        // Empeche de choisir un pokemon qui n'existe pas

        if (end_of_choice > 1 || end_of_choice < 0) {
            end_of_choice = 0;
            std::cout << "Vous n'avez selectioner aucun des pokemons disponible" << std::endl;
        };
    };

    return (player_pokemon_id);
}

// ------------------- //
// Focntion principale //
// ------------------- //

int main() {

    std::cout << "Bonjour jeune margoulin" << std::endl;

    int pokemon_id = pokemon_choice();

    Create_Pokemon();

    return 0;
}