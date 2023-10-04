#include <stdio.h>

int main () {

    char a;

    printf("Enter a character: ");
    scanf("%c",&a);

    char b = a +32;

    printf("Patate %c min et %c max\n",a,b);

    return 0;
}