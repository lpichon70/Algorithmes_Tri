#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * ! Les fonction de getMax et Initialize  EmptyTab sont déjà déclarés dans countingTab. 
 * TODO Faire un refactoring du code afin de créer une classe mère
 */

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

/**
 * Tri le tableau en utilisant la même méthode qu'un algorithme de counting sort
 */
void unitSort(int tab[], int n, int modulo)
{
    int countArray[10];
    initializeEmptyCountArray(countArray,10);

    for (int i = 0; i < n; i++)
    {
        int digit = (tab[i] % modulo) / (modulo / 10);
        countArray[digit]++;
    }

    setSumCountArray(countArray, 10);
    
    // Permets d'alouer dynamiquement de l'espace
    int* output = malloc(n * sizeof(int));

    // Utilisation de l'algorithme counting sort
    for (int i = n - 1; i >= 0; i--) {
        int digit = (tab[i] % modulo) / (modulo / 10);
        countArray[digit]--;
        output[countArray[digit]] = tab[i];
    }

    for (int i = 0; i < n; i++) {
        tab[i] = output[i];
    }

    free(output);

} 


/**
 * Algorithme de tri par base 
 */
void radix_sort(int tab[], int n){
    int max = getMaxValue(tab,n);

    int length = getLength(max);

    for (int i = 1; i <= length; i++)
    {
        int modulo = pow(10,i);
        unitSort(tab,n,modulo);
    }
    
}