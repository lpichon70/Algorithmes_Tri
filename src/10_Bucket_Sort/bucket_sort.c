#include "bucket_sort.h"
#include "../3_Insertion_Sort/insertion_sort.h"
#include "../utils/utils.h"

#include <stdio.h>
#include <stdbool.h>

#define BUCKET_COUNT 5


/**
 * Algorithme de tri par compartiments
 */
void bucket_sort(int tab[], int n)
{
    int max = getMaxValue(tab,n);
    int min = getMinValue(tab,n);

    int interval = (max - min + 1) / BUCKET_COUNT;

    int buckets[BUCKET_COUNT][n]; // tableau de seaux
    int bucket_sizes[BUCKET_COUNT] = {0}; // Tableau pour situer les index dans les seaux

    // Remplissage des seaux
    for (int i = 0; i < n; i++)
    {
        int index_bucket = (tab[i] - min) / interval;
        if (index_bucket >= BUCKET_COUNT) // Vérifie si le programme n'arrondi pas au supérieur l'index du seau     
        {
            index_bucket--;
        }
        buckets[index_bucket][bucket_sizes[index_bucket]++] = tab[i];
    }
    
    // Tri et insertion des seaux dans la tableau
    int k = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucket_sizes[i] > 0) {
            insertion_sort(buckets[i], bucket_sizes[i]);
            for (int j = 0; j < bucket_sizes[i]; j++) {
                tab[k++] = buckets[i][j];
            }
        }
    }


}