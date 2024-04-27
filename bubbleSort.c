#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

// worst, average: O(n^2)
// best: O(n)

void bubbleSort(int *unsorted, int size) {
    // for (int i = 0; i < size; i++) {
    //     int lowest = i;
    //     for (int v = i; v < size; v++) {
    //         if (unsorted[v] < unsorted[lowest]) {
    //             lowest = v;
    //         }
    //     }
    //     int temp = unsorted[i];
    //     unsorted[i] = unsorted[lowest];
    //     unsorted[lowest] = temp;
    // }
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

int main(int argc, char** argv) {
    int unsorted[50000];
    srand(time(NULL));
    for (int i = 0; i < 50000; i++) {
        unsorted[i] = (rand() % 89) + 10;
    }
    for (int i = 0; i < sizeof(unsorted) / sizeof(unsorted[0]); i++) {
        printf("%d ", unsorted[i]);
    } printf("\n");
    unsigned long start = GetTickCount();
    bubbleSort(unsorted, sizeof(unsorted) / sizeof(unsorted[0]));
    unsigned long delta = GetTickCount() - start;
    for (int i = 0; i < sizeof(unsorted) / sizeof(unsorted[0]); i++) {
        printf("%d ", unsorted[i]);
    } printf("\n");
    printf("time taken: %dms\n", delta);
    return 0;
}