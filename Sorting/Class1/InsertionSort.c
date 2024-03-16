#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Display(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);

    int *myArray = (int *) malloc (size * sizeof(int));
    for(int i = 0; i < size; i++) {
        scanf("%d", &myArray[i]);
    }

    Display(myArray, size);
    InsertionSort(myArray, size);
    Display(myArray, size);

    free(myArray);
    return 0;
}