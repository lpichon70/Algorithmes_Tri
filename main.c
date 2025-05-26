#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "src/1_Bubble_Sort/bubble_sort.h"
#include "src/2_Selection_Sort/selection_sort.h"
#include "src/3_Insertion_Sort/insertion_sort.h"
#include "src/4_Shell_Sort/shell_sort.h"
#include "src/5_Heap_Sort/heap_sort.h"
#include "src/6_Merge_Sort/merge_sort.h"
#include "src/7_Quick_Sort/quick_sort.h"
#include "src/8_Counting_Sort/counting_sort.h"
#include "src/9_Radix_Sort/radix_sort.h"
#include "src/10_Bucket_Sort/bucket_sort.h"


#define MAX_SIZE 50000

/**
 * Charge un tableau dans un fichier .TXT
 */
int load_array_from_file(const char *filename, int *array) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return -1;
    }

    int i = 0;
    while (fscanf(file, "%d", &array[i]) == 1 && i < MAX_SIZE) {
        i++;
    }

    fclose(file);
    return i;
}

/**
 * Affiche le tableau dans le terminal
 */
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

int main() {
    int tab[MAX_SIZE];
    char file_choice;
    char algo_choice;
    const char *filename = NULL;

    // Choix du tableau à trier
    printf("Quel tableau veux-tu trier ?\n");
    printf("  1. tabToSortExtraShort.txt (10 valeurs)\n");
    printf("  2. tabToSortShort.txt (50 valeurs)\n");
    printf("  3. tabToSortLong.txt (300 valeurs)\n");
    printf("  4. tabToSortVeryLong.txt (50 000 valeurs)\n");
    printf("Ton choix (1, 2, 3 ou 4) : ");
    scanf(" %c", &file_choice);

    if (file_choice == '1') {
        filename = "storage/tabToSortExtraShort.txt";
    } else if (file_choice == '2') {
        filename = "storage/tabToSortShort.txt";
    }
    else if (file_choice == '3') {
        filename = "storage/tabToSortLong.txt";
    }
     else if (file_choice == '4') {
        filename = "storage/tabToSortVeryLong.txt";
    }
    else {
        printf("Choix invalide.\n");
        return 1;
    }

    int size = load_array_from_file(filename, tab);
    if (size <= 0) {
        fprintf(stderr, "Erreur de chargement du tableau\n");
        return 1;
    }

    // Choix de l'algorithme de tri
    printf("\nQuel algorithme de tri veux-tu utiliser ?\n");
    printf("  a. Bubble Sort\n");
    printf("  b. Selection Sort\n");
    printf("  c. Insertion Sort\n");
    printf("  d. Shell Sort\n");
    printf("  e. Heap Sort\n");
    printf("  f. Merge Sort\n");
    printf("  g. Quick Sort\n");
    printf("  h. Counting Sort\n");
    printf("  i. Radix Sort\n");
    printf("  j. Bucket Sort\n");
    printf("Ton choix (a) : ");
    scanf(" %c", &algo_choice);

    printf("\nTableau avant tri :\n");
    print_array(tab, size);

    clock_t start = clock();

    switch (algo_choice) {
        case 'a':
            bubble_sort(tab, size);
            break;
        case 'b':
            selection_sort(tab, size);
            break;   
        case 'c':
            insertion_sort(tab, size);
            break;
        case 'd':
            shell_sort(tab, size);
            break;
        case 'e':
            heap_sort(tab, size);
            break;
        case 'f':
            merge_sort(tab, 0, size-1);
            break;
        case 'g':
            quick_sort(tab,0,size - 1);
            break;
        case 'h':
            counting_sort(tab, size);
            break;
        case 'i':
            radix_sort(tab, size);
            break; 
        case 'j':
            bucket_sort(tab, size);
            break;
        default:
            printf("Algorithme non reconnu.\n");
            return 1;
    }

    clock_t end = clock();
    double duration_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

    printf("\nTableau après tri :\n");
    print_array(tab, size);

    printf("\n⏱ Temps d'exécution : %.3f ms\n", duration_ms);

    return 0;
}
