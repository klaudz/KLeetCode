//
//  findMedianSortedArrays.c
//  kLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "findMedianSortedArrays.h"

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int numsSize = nums1Size + nums2Size;
    int *nums = malloc(sizeof(int) * numsSize);
    int i = 0, j = 0;
    for (int k = 0; k < numsSize; k++) {
        if (i >= nums1Size) {
            nums[k] = nums2[j++];
        } else if (j >= nums2Size) {
            nums[k] = nums1[i++];
        } else if (nums1[i] < nums2[j]) {
            nums[k] = nums1[i++];
        } else {
            nums[k] = nums2[j++];
        }
    }
    if (numsSize % 2 == 0) {
        int n = numsSize / 2;
        int m = n - 1;
        return (nums[m] + nums[n]) / 2.0;
    } else {
        int m = numsSize / 2.0;
        return nums[m];
    }
}

void test_findMedianSortedArrays()
{
    {
        int nums1[] = { 1, 3 };
        int nums2[] = { 2 };
        int nums1Size = sizeof(nums1) / sizeof(int);
        int nums2Size = sizeof(nums2) / sizeof(int);
        double ret = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
        printf("%f\n", ret);
    }
    
    {
        int nums1[] = { 1, 2 };
        int nums2[] = { 3, 4 };
        int nums1Size = sizeof(nums1) / sizeof(int);
        int nums2Size = sizeof(nums2) / sizeof(int);
        double ret = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
        printf("%f\n", ret);
    }
    
}
