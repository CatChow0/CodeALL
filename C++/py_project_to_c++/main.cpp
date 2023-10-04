//import des modules de base
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//simplification des noms
using namespace std;
using namespace sf;
//Personalisation de la fenetre
int main()
{
    Window fenetre;
    fenetre.create(VideoMode(1280, 720), "Wattchow"); //defini la taille initial
    while (fenetre.isOpen())
    {  
    }
    return 0;
}