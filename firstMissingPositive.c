//
//  firstMissingPositive.c
//  kLeetCode
//
//  Created by klaudz on 26/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"

int firstMissingPositive(int *nums, int numsSize) {
    
    // Note:
    //  If 'bool', 'true' and 'false' are used to malloc an boolean array,
    //  LeetCode would judge that the case below is wrong answer.
    //  Case:
    //      Input: { 1 }
    //      Output: 7
    //      Expect: 2
    
    size_t memsize = sizeof(char) * numsSize;
    char *b = malloc(memsize);
    memset(b, 0, memsize);
    
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        if (val > 0 && val < numsSize + 1) {
            b[val-1] = 1;
        }
    }
    
    int j = 0;
    while (b[j] == 1) {
        j++;
    }
    return j + 1;
}

int main(void)
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
