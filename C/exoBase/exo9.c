#include <stdio.h>
#include <stdbool.h>

int main() {

    int tent = 3;
    int PIN = 1234;
    int user_input;
    bool open = false;

    while (tent > 0) {

        printf("Code PIN: \n");
        scanf("%d", &user_input);
        if (user_input == PIN) {
            open = true;
            break;
        } else {
            tent = tent -1;
        }

    }

    if (open == true) {
        printf("Telephone est deverouille\n");
    } else {
        printf("Telephone est verouille\n");
    }

}