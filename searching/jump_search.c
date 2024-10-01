#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int jump_search(int arr[], int n, int target) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[MIN(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while (arr[prev] < target) {
        prev++;
        if (prev == MIN(step, n)) return -1;
    }

    if (arr[prev] == target) return prev;
    return -1;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int n = 20;
    int arr[20];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Ensure the array is sorted for Jump Search
    qsort(arr, n, sizeof(int), (int (*)(const void*, const void*))strcmp);

    printf("Sorted Array: ");
    print_array(arr, n);

    int target = arr[rand() % n];  // Choose a random element as target
    printf("Searching for: %d\n", target);

    clock_t start = clock();
    int result = jump_search(arr, n, target);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
