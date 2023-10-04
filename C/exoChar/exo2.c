#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char date[10];
    char nom[200];
    char prenom[200];
    char couleur[200];

    printf("Donnez les informations suivantes: \n");
    printf("Date de naissance: ");
    scanf("%s", &date);
    printf("Nom: ");
    scanf("%s", &nom);
    printf("Prenom: ");
    scanf("%s", &prenom);
    printf("Couleur des yeux: ");
    scanf("%s", &couleur);
    printf("Vous vous appelez %s %s, vous etes nee le %s et vos yeux sont %s\n", nom, prenom, date, couleur);

    return 0;
}
