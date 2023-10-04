#include <stdio.h>
#include <string.h>

int main() {
    char nom[100]; // Déclaration d'un tableau de caractères de taille 100
    printf("Entrez votre nom : ");
    fgets(nom, 100, stdin); // Lecture de la saisie utilisateur avec fgets()
    nom[strcspn(nom, "\n")] = 0; // Suppression du retour à la ligne en fin de chaîne

    printf("Contenu de la chaine : %s\n", nom);
    printf("Taille en memoire de la chaine : %ld octets\n", sizeof(nom));
    printf("Nombre de caracteres : %ld\n", strlen(nom));
    
    return 0;
}
