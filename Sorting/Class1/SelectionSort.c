#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int *arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        int min = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
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
    SelectionSort(myArray, size);
    Display(myArray, size);

    free(myArray);
    return 0;
}