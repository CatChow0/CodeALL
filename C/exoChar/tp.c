#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main () {
    
    int pv = 10;
    char mot_secret[7] = {'P','O','U','T','R','E','\0'};
    int taille_mot = strlen(mot_secret);
    // char mot_trouve[taille_mot+1] = {'-','-','-','-','-','-','\0'};
    char saisie_utilisateur;

    bool game_statue = false;
    
    while (game_statue == false) {

        printf("Pendu - chance restante : %d\nEntrez une lettre ", pv);
        scanf("%c", saisie_utilisateur);

        // Si la lettre est dans le mot a trouver
        if (strchr(mot_secret, saisie_utilisateur) != NULL) {
            
        }


    }



    return 0;
}