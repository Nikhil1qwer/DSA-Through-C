#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *arr, int size, int Target) {
    int left = 0, right = size - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == Target) {
            return mid;
        }
        if(arr[mid] > Target) {
            left = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    int size;
    scanf("%d", &size);

    int *arr = (int *) malloc (sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int Target;
    scanf("%d", &Target);

    int found = BinarySearch(arr, size, Target);

    if(found != -1) {
        printf("Element is at Index: %d", found);
    } else {
        printf("Element Not Found!!");
    }

    free(arr);
    return 0;
}