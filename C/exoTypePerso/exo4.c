#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition de la structure Etudiant
struct Etudiant {
    char nom[100];
    char prenom[100];
    float moyenne;
};

int main() {
    // Creation d'une liste d'etudiants
    struct Etudiant liste_etudiants[5] = {
        {"Papi", "Tiana", 3.6},
        {"LeG", "Erome", 14.2},
        {"Poutre", "Luc", 19.65},
        {"Jean", "Marie", 9.0},
        {"Bernard", "Antoine", 11.75}
    };

    // Affichage des etudiants ayant obtenu leur diplome
    printf("Liste des etudiants ayant obtenu leur diplome :\n");
    for (int i = 0; i < 5; i++) {
        if (liste_etudiants[i].moyenne >= 10.0) {
            printf("%s %s\n", liste_etudiants[i].prenom, liste_etudiants[i].nom);
        }
    }

    return 0;
}