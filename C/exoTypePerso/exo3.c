#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[20];
    int degats;
} Arme;

typedef struct {
    char nom[20];
    int pv;
    char classe[20];
    Arme arme;
} Personnage;

int main() {
    // Création des armes
    Arme melee = {"Poutre Divine", 150};
    Arme range = {"Bacon Fume Mythique", 155};

    // Création des personnages
    Personnage joueur1 = {"Pedro", 100, "GUERRIER", melee};
    Personnage joueur2 = {"Kevin", 80, "MAGE", range};

    // Affichage des informations
    printf("Informations du joueur 1 :\n");
    printf("Nom : %s\n", joueur1.nom);
    printf("PV : %d\n", joueur1.pv);
    printf("Classe : %s\n", joueur1.classe);
    printf("Arme : %s (%d degats)\n", joueur1.arme.nom, joueur1.arme.degats);

    printf("\nInformations du joueur 2 :\n");
    printf("Nom : %s\n", joueur2.nom);
    printf("PV : %d\n", joueur2.pv);
    printf("Classe : %s\n", joueur2.classe);
    printf("Arme : %s (%d degats)\n", joueur2.arme.nom, joueur2.arme.degats);

    return 0;
}
