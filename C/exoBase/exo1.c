#include <stdio.h>

int main () {

    int age;
    char nom[50];

    printf("Enter your age AND your name: \n");

    scanf("%d %s", &age, &nom);

    printf("Vous avez %d ans mr.%s", age, nom);

    return 0;
}

