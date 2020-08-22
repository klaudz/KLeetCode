//
//  reverseInteger.c
//  kLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"

#define reverse reverseInteger

#define Resolve 1

#if Resolve == 0

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

#elif Resolve == 1

int reverse(int x) {
    
    if (x == -2147483648) {
        return 0;
    }
    
    bool negative = (x < 0);
    int r = 0;
    int tmp = negative ? -x : x;
    while (tmp != 0) {
        int remainder = tmp % 10;
        int quotient = tmp / 10;
        if ((r >= 214748365) || (r >= 214748364 && remainder > (negative ? 7 : 8))) {
            r = 0;
            break;
        }
        r = r * 10 + remainder;
        tmp = quotient;
    }
    r = negative ? -r : r;
    return r;
}

#endif

int main(void)
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
    
    
    {
        int r = reverseInteger(2147447413);
        printf("%d\n", r);
    }
    {
        int r = reverseInteger(-2147447413);
        printf("%d\n", r);
    }
    {
        int r = reverseInteger(-2147483648);
        printf("%d\n", r);
    }
    {
        int r = reverseInteger(1463847412);
        printf("%d\n", r);
    }
    {
        int r = reverseInteger(1563847412);
        printf("%d\n", r);
    }
}
