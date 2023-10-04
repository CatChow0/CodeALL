#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    char chaine[] =  {'S','a','l','u','t',' ','l','e','s',' ','c','o','d','e','u','r','s','!','\0'};

    printf("%s", chaine);

    strcpy(chaine, "\n\nSalut");

    printf("%s");

    return 0;
}