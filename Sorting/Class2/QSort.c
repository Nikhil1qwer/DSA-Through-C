#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
     return ( *(int *)a - *(int *)b );
}

void peek(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }   printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);

    int *myArray = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        scanf("%d", &myArray[i]);
    }

    printf("Array Before Sorting: ");
    peek(myArray, size);
    qsort(myArray, size, sizeof(int), cmp); // qsort --> qicksort function call
    printf("Array After Sorting: ");
    peek(myArray, size);

    free(myArray);
    return 0;
}