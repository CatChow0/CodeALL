#include <stdio.h>
#include <math.h>

int main() {

    int a,b,res;
    char op;
    float div;
    printf("Entrer un calcul: ");
    scanf("%d %c %d",&a,&op,&b);
    if (op == '+') {
        res = a+b;
        printf("La somme de %d + %d = %d\n",a,b,res);
    }
    if (op == '-') {
        res = a-b;
        printf("La somme de %d - %d = %d\n",a,b,res);
    } if (op == '*') {
        res = a*b;
        printf("La somme de %d * %d = %d\n",a,b,res);
    } if (op == '/') {
        res = a/b;
        printf("La somme de %d / %d = %d\n",a,b,res);
    }
    return 0;
}

