#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// #include <include/progressbar.hpp>
#include <include/pokemon_list.h>
#include <include/game.h>
#include <include/get_data.h>

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

    float type_attaque_modifier = type_modifier(Player_Pokemon_Type, Enemy_Pokemon_Type); // Modifie les bonus dégàt en fonction type

    
    


    fight(Player_Starter_Name, Player_Starter_Health, Player_Starter_Attack, Player_Starter_Defense, Player_Pokemon_Type, Enemy_starter_Name, Enemy_Starter_Health, Enemy_Starter_Attack, Enemy_Starter_Defense, Enemy_Pokemon_Type); // Lance le combat


    // Permet d'ajouter un nouveau pokemon dans le fichier Pokemon.txt
    // Create_Pokemon(); 

    return 0;
}