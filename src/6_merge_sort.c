#include <stdio.h>
#include <stdbool.h>


/**
 * Fonction de fusion entre 2 tableaux triés
 */
void merge(int tab[],int left,int middle,int right){
    int n1 = middle - left + 1;
    int n2 = right - middle; 

    // Crée 2 tableaux temporaires
    int L[n1], R[n2];

    // Copie les données de droite et de gauche dans les tableaux temporaires
    for (int i = 0; i < n1; i++)
    {
       L[i] = tab[left + i];  
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = tab[middle + 1 + j];
    }

    // Fusionne les 2 tableaux dans la tableau principal
    int i = 0;
    int j = 0;
    int k = left;
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        }
        else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    // S'il reste des éléments dans le tableau de gauche
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }

    // S'il restd es éléments dans le tableau de droite
    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }
    
}


/**
 * Tri fusion
 */
void merge_sort(int tab[], int left, int right){

    if (left < right)
    {
        int middle = (left + right) / 2;

        merge_sort(tab, left, middle);
        merge_sort(tab, middle + 1, right);

        merge(tab, left, middle, right);
    }
}
