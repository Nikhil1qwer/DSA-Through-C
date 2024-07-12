#include <stdio.h>
#include <stdlib.h>

// Recursive 
int linearSearch(int *nums, int left, int right, int target) {
    if(left == right) return -1;

    if(nums[left] == target) {
        return left + 1;
    }

    return linearSearch(nums, left + 1, right, target);
}

int binarySearch(int* nums, int left, int right, int target) {
    if(left > right) return -1;

    int mid = left + (right - left) / 2;

    if(nums[mid] == target) {
        return mid + 1;
    }

    if(nums[mid] > target) {
        binarySearch(nums, left, mid - 1, target);
    }

    binarySearch(nums, mid + 1, right, target);
}

// Iterative
int linearSearch(int *nums, int left, int right, int target) {
    for(int i = left; i < right; i++) {
        if(nums[i] == target) {
            return i + 1;
        }
    }

    return -1;
}

int binarySearch(int* nums, int left, int right, int target) {
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            return mid + 1;
        }

        if(nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int size;
    scanf("%d", &size);

    int* nums = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int target;
    scanf("%d", &target);

    int isFoundLinear = linearSearch(nums, 0, size, target);
    if(isFoundLinear != -1) {
        printf("Element found at index: %d\n", isFoundLinear);
    } else {
        printf("Element Not Found!!\n");
    }

    int isFoundBinary = binarySearch(nums, 0, size - 1, target);
    if(isFoundBinary != -1) {
        printf("Element found at index: %d\n", isFoundBinary);
    } else {
        printf("Element Not Found!!\n");
    }
}