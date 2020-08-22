//
//  debug.c
//  KLeetCode
//
//  Created by klaudz on 11/21/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "debug.h"
#include "includes.h"

void print_nums(int *nums, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
