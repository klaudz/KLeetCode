//
//  reverseInteger.c
//  kLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "reverseInteger.h"

#define reverse reverseInteger

int reverse(int x) {
    
    bool negative = (x < 0);
    long long r = 0;
    long long tmp = negative ? -x : x;
    while (tmp != 0) {
        long long remainder = tmp % 10;
        long long quotient = tmp / 10;
        r = r * 10 + remainder;
        tmp = quotient;
    }
    r = negative ? -r : r;
    if (r > 2147483648 || r < -2147483647) r = 0;
    return (int)r;
}

void test_reverseInteger()
{
    {
        int r = reverseInteger(123);
        printf("%d\n", r);
    }
    {
        int r = reverseInteger(-123);
        printf("%d\n", r);
    }
    {
        int r = reverseInteger(1534236469);
        printf("%d\n", r);
    }
}
