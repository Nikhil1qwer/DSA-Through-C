#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *arr, int left, int right, int Target) {
    if(left > right) return -1;
    
    int mid = left + (right - left) / 2;
    
    if(arr[mid] == Target) {
        return mid;
    }
    if(arr[mid] > Target) {
        return BinarySearch(arr, left, mid - 1, Target);
    }
    
    return BinarySearch(arr, mid + 1, right, Target);
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
    
    int found = BinarySearch(arr, 0, size - 1, Target);

    if(found != -1) {
        printf("Element is at Index: %d", found);
    } else {
        printf("Element Does not Exist!!");
    }
    
    free(arr);
    return 0;
}