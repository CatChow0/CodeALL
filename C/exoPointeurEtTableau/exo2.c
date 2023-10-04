#include <stdio.h>

int main () {

    int a;
    int* p_int = 0;
    

    printf("Entrez une valeur: \n");
    scanf("%d", &a);
    p_int = &a;
    printf("Vous avez entrez %d qui est stocke a cette adresse: %p", *p_int, p_int);

    return 0;
}