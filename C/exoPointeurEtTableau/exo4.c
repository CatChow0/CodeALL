#include <stdio.h>

int main() {

    int i,j;
    int temp_max,max,min,temp_min,avg = 0;
    int tab1[] = {4,20,3,6,936}, tab2[5];

    int* p_int = 0;
    p_int = tab1;

    
    //Copier les éléments dans le tableau tab2 à partir de la fin du tableau tab1    
    for (i = 4, j = 0; i >= 0; i--, j++) {
        tab2[j] = tab1[i];
    }
    
    printf("\n\nLe tableau inverse est: ");
    for (i = 0; i < 5; i++) {
        printf("\n%d ", tab2[i]);
    }

    for (i = 0; i < 5; i++) {
        avg = avg + (tab1[i]);
        
    }

    avg = avg / 5;

    for (i = 0; i < 5; i++) {

        if (tab1[i] < 0) 
        {
            temp_max = tab1[i]*(-1);
        } else 
        {
            temp_max = tab1[i];
        };
        if (max < temp_max) 
        {
            max = temp_max;
        }
    }

    for (i = 0; i < 5; i++) {

        if (tab1[i] < 0) 
        {
            temp_min = tab1[i]*(-1);
        } else 
        {
            temp_min = tab1[i];
        };
        if (min > temp_min) 
        {
            min = temp_min;
        }
    }


    printf("\n\nVoici le tableau dans l'ordre: ");
    for (i = 0; i < 5; i++) {
        printf("\nContenu: %d, Addresse: %p, octet: %d, Index: %d, Moyenne: %d, Max: %d, Min: %d", *(tab1+i), p_int, sizeof(tab1[i]), i, avg,max,min);
    }



    return 0;
}