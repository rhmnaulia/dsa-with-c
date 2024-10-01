#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    bool swapped;
    int iterations = 0;
    int comparisons = 0;
    int swaps = 0;

    for (i = 0; i < n-1; i++) {
        swapped = false;
        for (j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
                swaps++;
            }
        }
        iterations++;

        // If no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }

    printf("Sorting completed in %d iterations\n", iterations);
    printf("Total comparisons: %d\n", comparisons);
    printf("Total swaps: %d\n", swaps);
}

void print_array(int arr[], int size) {
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n = 20;
    int arr[20];

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Generate random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start = clock();
    bubble_sort(arr, n);
    clock_t end = clock();

    printf("Sorted array: ");
    print_array(arr, n);

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
