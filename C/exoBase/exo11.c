#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int comparaison (int choixJoueur, int action);
 
int main()
{
    //varaible
    int action = 0;
    int choixJoueur = 0;
    int continuer = 1;
    const int MAX = 3, MIN = 1;
 
    srand(time(NULL));
 
    //accueille
    printf("===Pierre Feuille Ciseau===\n\n");
    printf("Regles:\nLa feuille gagne la pierre mais perd le ciseau.\nLa pierre gagne le ciseau mais perd la feuille\nLe ciseau gagne la feuille mais perd la pierre\n\n");
 
 
while (continuer == 1)
{
     action = (rand () % (MAX - MIN + 1)) + MIN;
 
 
//Choix du joueur.Si celui ci entre un mauvais nombre une boucle afficherais le menue du choix une nouvelle fois.
do
{
 
    printf("Choisiser le numero de votre action :\n1-Pierre\n2-Feuille\n3-Ciseau\n");
    scanf("%d", &choixJoueur);
    switch (choixJoueur)
    {
        case 1:
        printf("Vous avez choisi la pierre\n\n");
        break;
         case 2:
         printf("Vous avez choisie la feuille\n\n");
         break;
          case 3:
          printf("Vous avez choisi le ciseau\n\n");
          break;
           default:
           printf("Mauvais numero entre\n");
           break;
    }
 
}while (choixJoueur > 3);
//Détermine ce que l'ordinateur a choisie
    printf("L'ordinateur choisie:\n");
    switch (action)
    {
        case 1:
        printf("La Pierre\n");
        break;
         case 2:
         printf("La Feuille\n");
         break;
          case 3:
          printf("Le Ciseau\n");
          break;
    }
comparaison(choixJoueur, action);
//Pour recomencer une partie
printf("Pour continuer taper 1, pour areter taper un autre nombre:\n");
scanf("%d", &continuer);
printf("\n\n\n\n\n");
}
 
  return 0;
}
 
int comparaison (int choixJoueur, int action)
{
//si le joueur choisie la pierre
if (choixJoueur == 1 && action == 1)
printf("Match null\n\n\n");
else if (choixJoueur == 1 && action == 2)
printf("L'ordinateur gagne\n\n\n");
else if (choixJoueur == 1 && action == 3)
printf("Le joueur gagne\n\n\n");
//fin de comparaison pour le choix de la pierre par le joueur
//si le joueur choisie la feuille
else if (choixJoueur == 2 && action == 2)
printf("Match null\n\n\n");
else if (choixJoueur == 2 && action == 3)
printf("L'ordinateur gagne\n\n\n");
else if (choixJoueur == 2 && action == 1)
printf("Le joueur gagne\n\n\n");
//fin de comparaison pour le choix de la feuille par le joueur
//si le joueur choisie le ciseau
else if (choixJoueur == 3 && action == 3)
printf("Match null\n\n\n");
else if (choixJoueur == 3 && action == 1)
printf("L'ordinateur gagne\n\n\n");
else if (choixJoueur == 3 && action == 2)
printf("Le joueur gagne\n\n\n");
//fin de comparaison pour le choix du ciseau par le joueur
else
printf("Erreur lors de la comparaison des choix.\n\n\n");
 
return 0;
}