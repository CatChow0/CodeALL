#include <stdio.h>

int main() {

    char c;
    printf("Entrer un charactere: \n");
    scanf("%c", &c);

    char* p_char = 0;
    p_char = &c;

    printf("Le charactere %c est stocker a cette adresse %p et pese %d\n", c, p_char, sizeof(c));


    return 0;    
}