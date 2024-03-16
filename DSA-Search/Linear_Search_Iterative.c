#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int *nums, int numsSize, int Target) {
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == Target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    scanf("%d", &size);

    int *myArray = (int *) malloc (sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &myArray[i]);
    }

    int Target;
    scanf("%d", &Target);

    int found = LinearSearch(myArray, size, Target);
    if(found != -1) {
        printf("The Element is at Index: %d", found);
    } else {
        printf("The Element Does not Exist");
    }

    free(myArray);
    return 0;
}