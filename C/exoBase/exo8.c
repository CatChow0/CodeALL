#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {

    int n;
    int base = 0;
    double val;
    val = PI/180;
    printf("Entrer un nombre entre 0 et 360: \n");
    scanf("%d", &n);
    double res[n];

    if (n < 0 || n > 360) {
        printf("Le nombre est invalide \n");
    } else {
        for (int i = 0; i <= n; i++) {
            res[i] = cos(val*base);
            base = base+1;
        }

    }

    for (int i = 0; i <= n; i++) {
        printf("%.8lf\n", res[i]);
    }


    return 0;
}