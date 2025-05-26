#include "bubble_sort.h"

#include <stdbool.h>
#include <stdio.h>

/**
 * Fonction de tri à bulle
 * Compléxité O(n²)
 */
void bubble_sort(int tab[], int n) {
    bool exchange;
    do {
        exchange = false;
        for (int i = 0; i < n - 1; i++) {
            if (tab[i] > tab[i + 1]) {
                int temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                exchange = true;
            }
        }
        n--; 
    } while (exchange);
}

