//
//  twoSum.c
//  kLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "twoSum.h"

int *twoSum(int *nums, int numsSize, int target) {
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int *ret = malloc(2 * sizeof(int));
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return NULL;
}

void test_twoSum()
{
    int nums[] = { 2, 7, 11, 15 };
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 9;
    
    int *ret = twoSum(nums, numsSize, target);
    if (ret) {
        printf("[%d, %d]\n", ret[0], ret[1]);
    } else {
        printf("NULL\n");
    }
}
