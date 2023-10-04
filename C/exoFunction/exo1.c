#include <stdio.h>

int min(int a, int b) {

    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {

    int first;
    int second;

    printf("Entrez 2 nombre: ");
    scanf("%d %d", &first, &second);

    printf("Min : %d\nMax : %d\nResultat %d < %d ", min(first, second), max(first, second), min(first, second), max(first, second));
    return 0;
}
