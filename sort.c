#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

// all cases: O(n^2)

void selectionSort(int *unsorted, int size) {
    for (int i = 0; i < size; i++) {
        int lowest = i;
        for (int v = i; v < size; v++) {
            if (unsorted[v] < unsorted[lowest]) {
                lowest = v;
            }
        }
        int temp = unsorted[i];
        unsorted[i] = unsorted[lowest];
        unsorted[lowest] = temp;
    }
}

// worst, average: O(n^2)
// best: O(n)

void bubbleSort2(int *unsorted, int size) {
    for (int i = 1; i < size; i++) {
        for (int v = 0; v < size - 1; v++) {
            if (unsorted[v] > unsorted[v + 1]) {
                int temp = unsorted[v];
                unsorted[v] = unsorted[v + 1];
                unsorted[v + 1] = temp;
            }
        }
    }
}

void bubbleSort(int *unsorted, int size) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < size - 1; i++) {
            if (unsorted[i] > unsorted[i + 1]) {
                int temp = unsorted[i];
                unsorted[i] = unsorted[i + 1];
                unsorted[i + 1] = temp;
                sorted = false;
            }
        }
    }
}

// worst, average: O(n^2)
// best: O(n)

void insertionSort(int *unsorted, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (unsorted[i] < unsorted[i + 1]) {
            int temp = unsorted[i];
            unsorted[i] = unsorted[i + 1];
            unsorted[i + 1] = temp;
            for (int v = i; v > 1; v--) {
                if (unsorted[v] < unsorted[v - 1]) {
                    temp = unsorted[v];
                    unsorted[v] = unsorted[v - 1];
                    unsorted[v - 1] = temp;
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    int unsorted[50000];
    int unsorted2[50000];
    int unsorted3[50000];
    int unsorted4[50000];
    srand(time(NULL));
    for (int i = 0; i < 50000; i++) {
        unsorted[i] = (rand() % 89) + 10;
        unsorted2[i] = unsorted[i];
        unsorted3[i] = unsorted[i];
        unsorted4[i] = unsorted[i];
    }
    for (int i = 0; i < sizeof(unsorted) / sizeof(unsorted[0]); i++) {
        printf("%d ", unsorted[i]);
    } printf("\n");

    unsigned long start = GetTickCount();
    bubbleSort(unsorted, sizeof(unsorted) / sizeof(unsorted[0]));
    unsigned long delta = GetTickCount() - start;
    start = GetTickCount();
    bubbleSort2(unsorted2, sizeof(unsorted) / sizeof(unsorted[0]));
    unsigned long delta2 = GetTickCount() - start;
    start = GetTickCount();
    selectionSort(unsorted3, sizeof(unsorted) / sizeof(unsorted[0]));
    unsigned long delta3 = GetTickCount() - start;
    start = GetTickCount();
    insertionSort(unsorted4, sizeof(unsorted) / sizeof(unsorted[0]));
    unsigned long delta4 = GetTickCount() - start;

    for (int i = 0; i < sizeof(unsorted) / sizeof(unsorted[0]); i++) {
        printf("%d ", unsorted[i]);
    } printf("\n");
    printf("time taken (bubble sort 1): %dms\ntime taken (bubble sort 2): %dms\ntime taken (selection sort): %dms\ntime taken (insertion sort): %dms\n", delta, delta2, delta3, delta4);
    return 0;
}