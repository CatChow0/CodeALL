#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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

int pokemon_choice() {

    int end_of_choice = 0;
    while (end_of_choice == 0) {
        std::cout << "Entre le numeros pour choisir ton pokemon de depart" << std::endl;
        std::cout << << "[1],"  << "[2],"<<  << "[3]" << std::endl;
        std::cin >> player_pokemon_id;
        switch (player_pokemon_id)
        {
        case 1:
            std::cout << "Vous avez selectioner" << << "de type : " <<  << std::endl;
            break;
        case 2:
            std::cout << "Vous avez selectioner" << << "de type Eau" << std::endl;
            break;
        case 3:
            std::cout << "Vous avez selectioner" << << "de type Plante" << std::endl;
            break;
        default:
            break;
        }
        std::cout << "Valider le choix" << std::endl;
        std::cin >> end_of_choice;
        if (end_of_choice > 1 || end_of_choice < 0) {
            end_of_choice = 0;
            std::cout << "Vous n'avez selectioner aucun des pokemons disponible" << std::endl;
        };
    };

    return (player_pokemon_id);
}



int main() {

    std::cout << "Bonjour jeune margoulin" << std::endl;

    int pokemon_id = pokemon_choice();

    return 0;
}