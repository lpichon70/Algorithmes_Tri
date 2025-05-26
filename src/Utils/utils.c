#include "utils.h"
#include <stdio.h>
#include <limits.h>


/**
 * Récupère la plus petite valeur du tableau
 */
int getMinValue(int tab[], int  n){
    int min = tab[0];

    for (int i = 1; i < n; i++)
    {
        if (tab[i] < min) min = tab[i];
    }

    return min;
    
}


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
 * Retourne la longueur d'un entier
 */
int getLength(int n)
{
    int lenght = 0;

    if (n == 0) return 1;

    while (n != 0)
    {
        n /= 10;
        lenght++;
    }

    return lenght;    
}