//
//  27_remove_element.c
//  KLeetCode
//
//  Created by klaudz on 11/19/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"
#include "common/sorts.h"

#define Resolve 2

#if Resolve == 0

int removeElement(int *nums, int numsSize, int val) {
    
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == val) {
            for (int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j+1];
            }
            numsSize--;
        } else {
            i++;
        }
    }
    return numsSize;
}

#elif Resolve == 1

int removeElement(int *nums, int numsSize, int val) {
    quick_sort(nums, numsSize);
    int firstIndex = -1, endIndex = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            if (firstIndex == -1) firstIndex = i;
            endIndex = i;
        } else if (nums[i] > val) {
            if (firstIndex >= 0) {
                nums[firstIndex + (i - endIndex - 1)] = nums[i];
            } else {
                break;
            }
        }
    }
    if (firstIndex >= 0) numsSize -= (endIndex - firstIndex + 1);
    return numsSize;
}

#elif Resolve == 2

int removeElement(int *nums, int numsSize, int val) {
    int newSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[newSize++] = nums[i];
        }
    }
    return newSize;
}

#endif

int main(void)
{
    {
        int val = 3;
        int nums[] = { 3, 2, 2, 3 };
        int oldSize = sizeof(nums) / sizeof(int);
        int newSize = removeElement(nums, oldSize, val);
        printf("[%d] ", newSize);
        for (int i = 0; i < newSize; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
    {
        int val = 3;
        int nums[] = { 1, 3, 2, 2, 3, 2 };
        int oldSize = sizeof(nums) / sizeof(int);
        int newSize = removeElement(nums, oldSize, val);
        printf("[%d] ", newSize);
        for (int i = 0; i < newSize; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
}
