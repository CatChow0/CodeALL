#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition de la structure Personne
typedef struct {
    char nom[50];
    char telephone[20];
} Personne;

// Fonction pour saisir une personne
void saisirPersonne(Personne *p) {
    printf("Entrez le nom : ");
    scanf("%s", p->nom);
    printf("Entrez le numero de telephone : ");
    scanf("%s", p->telephone);
}

// Fonction pour afficher une personne
void afficherPersonne(Personne p) {
    printf("Nom : %s\n", p.nom);
    printf("Telephone : %s\n", p.telephone);
}

int main() {
    // Declaration d'une liste de personnes
    Personne listePersonnes[100];
    int nbPersonnes = 0;

    // Boucle pour saisir des personnes tant que l'utilisateur le souhaite
    char reponse;
    do {
        // Saisie d'une personne
        saisirPersonne(&listePersonnes[nbPersonnes]);
        nbPersonnes++;

        // Demande a l'utilisateur s'il veut ajouter une autre personne
        printf("Voulez-vous ajouter une autre personne ? (O/N) ");
        scanf(" %c", &reponse);
        getchar(); // consomme le retour a la ligne laisse par scanf

    } while (reponse == 'O' || reponse == 'o');

    // Affichage de toutes les personnes saisies
    for (int i = 0; i < nbPersonnes; i++) {
        printf("\nPersonne %d :\n", i+1);
        afficherPersonne(listePersonnes[i]);
    }

    return 0;
}
