#include <stdio.h>
#include <string.h>
int main() {FILE* pt_fichier = fopen("Readme.txt" , "a");int user;printf("Combien de patate: \n");scanf("%d", &user);for(int i = 0; i < user; i++) {if( fputs("Patate \n", pt_fichier) != 0)printf("Error");}if( fputs("Patate", pt_fichier) != 0)printf("Error");return 0;}