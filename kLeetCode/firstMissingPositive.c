//
//  firstMissingPositive.c
//  kLeetCode
//
//  Created by klaudz on 26/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "firstMissingPositive.h"

int firstMissingPositive(int *nums, int numsSize) {
    
    size_t memsize = sizeof(bool) * numsSize;
    bool *b = malloc(memsize);
    memset(b, false, memsize);
    
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val > 0 && val < numsSize + 1) {
            b[val-1] = true;
        }
    }
    
    int j = 0;
    while (b[j]) {
        j++;
    }
    return j + 1;
}

void test_firstMissingPositive()
{
    {
        int nums[] = { 1, 2, 0 };
        int numsSize = sizeof(nums) / sizeof(int);
        printf("%d\n", firstMissingPositive(nums, numsSize));
    }
    {
        int nums[] = { 3, 4, -1, 1 };
        int numsSize = sizeof(nums) / sizeof(int);
        printf("%d\n", firstMissingPositive(nums, numsSize));
    }
    {
        int nums[] = { };
        int numsSize = sizeof(nums) / sizeof(int);
        printf("%d\n", firstMissingPositive(nums, numsSize));
    }
    {
        int nums[] = { 1 };
        int numsSize = sizeof(nums) / sizeof(int);
        printf("%d\n", firstMissingPositive(nums, numsSize));
    }
    {
        int nums[] = { 1, 3 };
        int numsSize = sizeof(nums) / sizeof(int);
        printf("%d\n", firstMissingPositive(nums, numsSize));
    }
}
