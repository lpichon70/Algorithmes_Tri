#include "counting_sort.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * Rempli le tableau count par les bonnes valeurs
 * @param n Nombre d'élément du tableau initiale
 */
void fillCountArray(int countArray[], int tab[], int n){

    for (int i = 0; i < n; i++)
    {
        countArray[tab[i]]+=1;
    }  
}

/**
 * Algorithme count sort final
 * Remet les éléments dans le tableau afin de le trier
 */
void counting_sort(int tab[], int n){
    int max = getMaxValue(tab,n);
    
    int countArray[max+1];
    int tempArray[n];

    initializeEmptyCountArray(countArray,max+1);
    
    fillCountArray(countArray, tab, n);

    setSumCountArray(countArray, max+1);

    for (int i = n; i > 0; i--)
    {
        int value = tab[i-1];
        if (countArray[value] > 0)
        {
            countArray[value] -= 1;
            tempArray[countArray[value]] = value;
        }        
    }

    for (int i = 0; i < n; i++) {
        tab[i] = tempArray[i];
    }   
    
}