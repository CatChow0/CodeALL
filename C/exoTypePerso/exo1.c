#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Ville
struct Ville {
    char nom[50];
    long nombreHabitants;
};

// Fonction pour échanger deux villes
void echangerVilles(struct Ville *v1, struct Ville *v2) {
    struct Ville temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

// Fonction pour trier la liste de villes par nombre d'habitants (tri bulle)
void classerVilles(struct Ville *villes, int nombreVilles) {
    int i, j;
    for (i = 0; i < nombreVilles-1; i++) {
        for (j = 0; j < nombreVilles-i-1; j++) {
            if (villes[j].nombreHabitants < villes[j+1].nombreHabitants) {
                echangerVilles(&villes[j], &villes[j+1]);
            }
        }
    }
}

// Fonction pour afficher le classement des villes
void afficherClassement(struct Ville *villes, int nombreVilles) {
    printf("Classement des villes :\n");
    for (int i = 0; i < nombreVilles; i++) {
        printf("%d. %s - %ld habitants\n", i+1, villes[i].nom, villes[i].nombreHabitants);
    }
}

int main() {
    // Création d'une liste de villes non classée
    struct Ville villes[] = {
        {"Paris", 2190327},
        {"Marseille", 861635},
        {"Lyon", 515695},
        {"Toulouse", 479553},
        {"Nice", 340017}
    };
    int nombreVilles = sizeof(villes) / sizeof(villes[0]);

    // Tri de la liste de villes par nombre d'habitants
    classerVilles(villes, nombreVilles);

    // Affichage du classement des villes
    afficherClassement(villes, nombreVilles);

    return 0;
}
