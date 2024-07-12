#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* nums, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    scanf("%d", &size);

    int* nums = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    bubbleSort(nums, size);

    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    
}