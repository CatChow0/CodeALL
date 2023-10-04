#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int De (int a) {

    srand(time(NULL));

    int nb_face = rand() % a;

    return nb_face;
}


int main () {

    int Taille_De;

    printf ("Choisissez le nombre de face du dé : \n");

    scanf("%d", &Taille_De);

    printf ("Nombre : %d\n", De(Taille_De));
    return 0;
}