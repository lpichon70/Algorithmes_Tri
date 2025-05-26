#include <stdio.h>
#include <stdbool.h>

/**
 * Fonction récursive qui parcours l'arbre binaire pour faire remonter la plus grande valeur à la racine
 */
void heapify(int tab[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && tab[left] > tab[largest])
        largest = left;

    if (right < n && tab[right] > tab[largest])
        largest = right;

    if (largest != i) {
        int temp = tab[i];
        tab[i] = tab[largest];
        tab[largest] = temp;

        heapify(tab, n, largest); 
    }
}

/**
 * Fonction d'organisation d'un tableau en arbre binaire max heap (chaques parents ont une valeur plus grande que les enfants)
 */
void buildMaxHeap(int tab[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(tab, n, i);
    }
}

/**
 * Fonction de tri à bulle
 * Compléxité O(n²)
 */
void heap_sort(int tab[], int n) {

    buildMaxHeap(tab,n);

    for (int i = n-1; i >= 0; i--)
    {
        int root = tab[0];
        tab[0] = tab[i];
        tab[i] = root;

        heapify(tab,i,0);
    }
}
