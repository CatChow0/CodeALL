#include <stdio.h>

int main() {

    int a;
    int b;


    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a > b) {
        int diff = a - b;
        printf("%d > %d\n donc la difference = %d", a, b, diff);
    } else if (a < b) {
        int diff = b - a;
        printf("%d < %d\n donc la difference = %d", a, b, diff);
    } else {
        int diff = a - b;
        printf("%d == %d\n donc la difference = %d", a, b, diff);
    }


}