#include <stdbool.h>

/**
 * Fonction de tri par sélection
 * Complexité O(n²)
 */
void selection_sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int position_min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[position_min])
            {
                position_min = j;
            }
        }
        if (position_min != i)
        {
            int temp = arr[i];
            arr[i] = arr[position_min];
            arr[position_min] = temp;
        }
    }
}