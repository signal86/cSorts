#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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
    selectionSort(unsorted, sizeof(unsorted) / sizeof(unsorted[0]));
    for (int i = 0; i < sizeof(unsorted) / sizeof(unsorted[0]); i++) {
        printf("%d ", unsorted[i]);
    } printf("\n");
    unsigned long delta = GetTickCount() - start;
    printf("time taken: %dms\n", delta);
    return 0;
}