#include <stdio.h>
#include <stdlib.h>

#include "src/1_bubble_sort.c"
#include "src/2_selection_sort.c"
#include "src/3_insertion_sort.c"
#include "src/4_shell_sort.c"
#include "src/5_heap_sort.c"
#include "src/6_merge_sort.c"
#include "src/7_quick_sort.c"
#include "src/8_counting_sort.c"
#include "src/9_radix_sort.c"
#include "src/10_bucket_sort.c"


#define MAX_SIZE 500

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
    printf("Ton choix (1, 2 ou 3) : ");
    scanf(" %c", &file_choice);

    if (file_choice == '1') {
        filename = "C:/Users/urb2584/Desktop/Perso/new_tri_algos/Storage/tabToSortExtraShort.txt";
    } else if (file_choice == '2') {
        filename = "C:/Users/urb2584/Desktop/Perso/new_tri_algos/Storage/tabToSortShort.txt";
    }
    else if (file_choice == '3') {
        filename = "C:/Users/urb2584/Desktop/Perso/new_tri_algos/Storage/tabToSortLong.txt";
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

    printf("\nTableau après tri :\n");
    print_array(tab, size);

    return 0;
}
