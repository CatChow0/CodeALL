#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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