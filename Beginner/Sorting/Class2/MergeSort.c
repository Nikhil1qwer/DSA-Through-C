#include <stdio.h>
#include <stdlib.h>

void conquer(int* arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int dp[right - left + 1];
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            dp[k++] = arr[i++]; // n
        } else {
            dp[k++] = arr[j++];
        }
    }

    while(i <= mid) { // n
        dp[k++] = arr[i++];
    }

    while(j <= right) { // n
        dp[k++] = arr[j++];
    }

    k = 0;

    for(int l = left; i < right; i++) {  // n
        arr[i] = dp[k++];
    }

}

void Merge(int *arr, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int dp[right - left + 1];

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            dp[k++] = arr[i++];
        } else {
            dp[k++] = arr[j++];
        }
    }
    
    while(i <= mid) {
        dp[k++] = arr[i++];
    }

    while(j <= right) {
        dp[k++] = arr[j++];
    }

    k = 0;
    for(int z = left; z <= right; z++) {
        arr[z] = dp[k++];
    }
} 



// Recursive.. // O(N * log(N))
void MergeSort(int *arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void Display(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }   printf("\n");
}

int main() {
    int size;
    scanf("%d", &size);

    int *myArray = (int *) malloc (size * sizeof(int));
    for(int i = 0; i < size; i++) {
        scanf("%d", &myArray[i]);
    }

    Display(myArray, size);
    MergeSort(myArray, 0, size - 1);
    Display(myArray, size);

    free(myArray);
    return 0;
}