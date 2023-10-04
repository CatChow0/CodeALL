#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main() {

    float rayon;

    printf("Entre le rayon: \n");
    scanf("%f", &rayon);

    float perimeter = 2 * PI * rayon;
    float area = PI * pow(rayon, 2);
    float volume = 4/3 * PI * pow(rayon, 3);

    printf("Avec un rayon %.2f, on obtient : \n un perimetre de %.2f, une aire de %.2f et un volume de %.2f\n", rayon, perimeter, area, volume);

    return 0;
}