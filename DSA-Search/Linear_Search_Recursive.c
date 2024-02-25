#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int *nums, int index, int numsSize, int Target) {
    if(index == numsSize) return -1;

    if(nums[index] == Target) {
        return index;
    }

    return LinearSearch(nums, index + 1, numsSize, Target);
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

    int found = LinearSearch(myArray, 0, size, Target);
    if(found != -1) {
        printf("The Element is at Index: %d", found);
    } else {
        printf("The Element Does not Exist");
    }

    free(myArray);
    return 0;
}