//
//  sorts.c
//  KLeetCode
//
//  Created by klaudz on 11/20/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "sorts.h"

void insertion_sort(int *nums, int n)
{
    for (int i = 1; i < n; i++) {
        int x = nums[i];
        int j = i - 1;
        if (nums[j] < x) {
            continue;
        }
        while (nums[j] > x) {
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = x;
    }
}

void selection_sort(int *nums, int n)
{
    for (int i = 0; i < n - 1; i++) {
        int jm = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[jm]) {
                jm = j;
            }
        }
        if (jm != i) {
            int tmp = nums[jm]; nums[jm] = nums[i]; nums[i] = tmp;
        }
    }
}

void bubble_sort(int *nums, int n)
{
    int i = n - 1;
    while (i > 0) {
        int p = 0;
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                int tmp = nums[j]; nums[j] = nums[j+1]; nums[j+1] = tmp;
                p = j;
            }
        }
        i = p;
    }
    /*
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j+1]) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
     */
}

void quick_sort(int *nums, int n)
{
    if (n > 1) {
        int p = nums[0];
        int low = 0, high = n - 1;
        while (low < high) {
            while (low < high && nums[high] >= p) high--;
            int tmpH = nums[high]; nums[high] = nums[low]; nums[low] = tmpH;
            while (low < high && nums[low] <= p) low++;
            int tmpL = nums[high]; nums[high] = nums[low]; nums[low] = tmpL;
        }
        quick_sort(nums, low);
        quick_sort(nums+low+1, n-low-1);
    }
}
