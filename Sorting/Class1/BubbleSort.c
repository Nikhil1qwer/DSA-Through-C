#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void BubbleSort(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] > arr[j + 1]) {   
            
            swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void Display(int *arr, int n) {
    for(int i = 0; i < n; i++) {
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
    BubbleSort(myArray, size);
    Display(myArray, size);

    free(myArray);
    return 0;
}