#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
        res = 0.75;
    } else if ( Attack_Pokemon_Type == "Plante" && Target_Pokemon_Type == "Feu") {
        res = 1.25;
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