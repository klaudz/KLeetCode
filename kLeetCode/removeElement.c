//
//  removeElement.c
//  kLeetCode
//
//  Created by klaudz on 11/19/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "removeElement.h"

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

void test_removeElement()
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
