#include <stdio.h>

int main () {

    int age = 23;
    int* pointeur_age;

    printf("Quel est votre age ?\n");
    scanf("%d", pointeur_age);
    printf("Votre age est %d\n", *pointeur_age);

    return 0;
}
