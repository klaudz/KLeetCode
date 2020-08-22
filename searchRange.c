//
//  searchRange.c
//  kLeetCode
//
//  Created by klaudz on 11/27/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "searchRange.h"

int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
    
    *returnSize = 2;
    size_t memsize = sizeof(int) * *returnSize;
    int *ret = malloc(memsize);
    memset(ret, -1, memsize);
    
    if (numsSize == 0 || target < nums[0] || target > nums[numsSize-1]) {
        return ret;
    }
    if (numsSize == 1 && target == nums[0]) {
        ret[0] = ret[1] = 0;
        return ret;
    }
    
    // Find starting position
    int size = numsSize / 2;
    int ps = 0;
    while (size >= 0 && ret[0] == -1) {
        int pm = ps + size;
        int mid = nums[pm];
        if (mid == target && (pm == 0 || (pm > 0 && nums[pm-1] != target))) {
            ret[0] = pm;
        } else if (size == 0) {
            size = -1;
        } else if (mid >= target) {
            size /= 2;
        } else {
            ps = pm + 1;
            size = (numsSize - ps) / 2;
        }
    }
    if (ret[0] != -1) {
        // Find ending position
        int offset = ret[0];
        nums += offset;
        numsSize -= offset;
        
        int size = numsSize / 2;
        int ps = 0;
        while (size >= 0 && ret[1] == -1) {
            int pm = ps + size;
            int mid = nums[pm];
            if (mid == target && (pm == numsSize - 1 || (pm < numsSize - 1 && nums[pm+1] != target))) {
                ret[1] = pm + offset;
            } else if (size == 0) {
                size = -1;
            } else if (mid <= target) {
                ps = pm + 1;
                size = (numsSize - ps) / 2;
            } else {
                size /= 2;
            }
        }
    }
    
    return ret;
}

void test_searchRange()
{
    {
        int nums[] = { 5, 7, 7, 8, 8, 10 };
        int size = sizeof(nums) / sizeof(int);
        int target = 8;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    {
        int nums[] = { };
        int size = sizeof(nums) / sizeof(int);
        int target = 8;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    {
        int nums[] = { 1 };
        int size = sizeof(nums) / sizeof(int);
        int target = 1;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    {
        int nums[] = { 2 };
        int size = sizeof(nums) / sizeof(int);
        int target = 1;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    {
        int nums[] = { 1, 1 };
        int size = sizeof(nums) / sizeof(int);
        int target = 1;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    {
        int nums[] = { 1, 5 };
        int size = sizeof(nums) / sizeof(int);
        int target = 8;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    {
        int nums[] = { 9, 19 };
        int size = sizeof(nums) / sizeof(int);
        int target = 8;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    {
        int nums[] = { 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 9, 9, 11, 11, 11, 12, 12, 12, 12 };
        int size = sizeof(nums) / sizeof(int);
        int target = 12;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
    {
        int nums[] = { 0, 0, 0, 0, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 7, 7, 8, 9, 9, 9, 10 };
        int size = sizeof(nums) / sizeof(int);
        int target = 10;
        int retSize = 0;
        int *ret = searchRange(nums, size, target, &retSize);
        printf("[%d, %d]\n", ret[0], ret[1]);
    }
}
