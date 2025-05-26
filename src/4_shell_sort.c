#include <stdbool.h>


/**
 * Fonction de tri par coque
 */
void shell_sort(int arr[], int n){

    for (int interval = n / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Utilisation de l'algorithme de tri par insertion
            while (j >= interval && arr[j - interval] > temp) {
                arr[j] = arr[j - interval];
                j -= interval;
            }

            arr[j] = temp;
        }
    }    
}