#include "quick_sort.h"

#include <stdio.h>
#include <stdbool.h>

/**
 * Échange 2 valeurs d'un tableau
 */
void swap(int tab[],int index_1, int index_2){
    int temp = tab[index_1];
    tab[index_1] = tab[index_2];
    tab[index_2] = temp;
}

/**
 * Fonction de gestion du pivot
 */
int pivot(int tab[], int left, int right){

    int pivot = tab[right];
    int i = left-1; // Index qui permets de créer une limite entre les plus petites valeurs du pivot et les plus grandes.

    for (int j = left; j < right; j++)
    {
        if (pivot >= tab[j])
        {
            i++;
            swap(tab,i,j);
        }
    }

    swap(tab,i+1,right);

    return i + 1; // retourne la position du pivot
}

/**
 * Algorithme de tri rapide
 */
void quick_sort(int tab[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = pivot(tab,left,right);
        quick_sort(tab, left, pivotIndex - 1);
        quick_sort(tab, pivotIndex + 1, right);
    }    
}