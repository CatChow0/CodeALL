#include <stdio.h>

int main () {


    char a;
    printf("entrez une lettre : \n");

    scanf("%c", &a);

    printf("La lettre en ASCII(dec) est %d et en ASCII(hex) est %x\n", a, a);

    return 0;
}