#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} 

//lomputoo
int partition1(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// naive
int partition(int *arr, int low, int high) {
    int k = 0;
    int dp[high - low + 1];
    int pivot = arr[low];
    
    for(int i = low + 1; i <= high; i++) {
        if(arr[i] <= pivot) {
            dp[k++] = arr[i];
        }
    }

    int PivotIndex = low + k;
    dp[k++] = pivot;

    for(int i = low + 1; i <= high; i++) {
        if(arr[i] > pivot) {
            dp[k++] = arr[i];
        }
    }

    for(int i = 0; i < k; i++) {
        arr[low + i] = dp[i];
    }

    return PivotIndex;
}

void quicksort(int *arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1); // 0 <> -1
        quicksort(arr, pi + 1, high); // 1 <> 4

    }
}

int main() {
    int size;
    scanf("%d", &size);

    int *nums = (int *) malloc (sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    quicksort(nums, 0, size - 1);

    for(int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    free(nums);
    return 0;
}
