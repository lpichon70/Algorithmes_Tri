#include <stdio.h>
#include <stdbool.h>

/**
 * Retourne l'entier le plus grand du tableau.
 */
int getMaxValue(int tab[], int n)
{
    int idMax = 0;

    for (int i = 1; i < n; i++)
    {
        if (tab[i] > tab[idMax])
        {
            idMax = i;
        }
        
    }

    return tab[idMax];
    
}

/**
 * Initialise le tableau avec des 0
 * @param n La taille du tableau Count
 */
void initializeEmptyCountArray(int countArray[], int n){
    for (int i = 0; i < n; i++)
    {
        countArray[i] = 0;
    }
}

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
 * Changement de la somme de chanque valeur du tableau : Changement de la somme tab[i] = tab[i] + tab[i-1]
 * Cette partie est une spécificité de l'algo
 * @param n La taille du tableau Count
 */
void setSumCountArray(int countArray[], int n){

    for (int i = 1; i < n; i++)
    {
        countArray[i] += countArray[i-1];
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