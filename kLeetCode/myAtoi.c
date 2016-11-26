//
//  myAtoi.c
//  kLeetCode
//
//  Created by klaudz on 11/26/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "myAtoi.h"

#define SUPPORTS_OCTAL 0 // Note: This problem in LeetCode doesn't support octal

int myAtoi(char *str) {
    
    int r = 0;
    int radix = 10;
    bool positive = true;
    bool overflow = false;
    
    for ( ; str[0] == ' '; ++str) ;
    
    if (str[0] == '+') {
        ++str;
    } else if (str[0] == '-') {
        ++str;
        positive = false;
    }
    
    if (str[0] == '0') {
        ++str;
        if (str[0] == 'x') {
            radix = 16;
            ++str;
        } else {
#if SUPPORTS_OCTAL
            radix = 8;
#else
            --str;
#endif
        }
    }
    
    int i = 0;
    while (str[i] != 0) {
        char c = str[i++];
        int t = (c >= '0' && c <= (radix > 8 ? '9' : '7')) ? (c - '0') :
                (radix == 16 ? (
                    (c >= 'a' && c <= 'f') ? (c - 'a' + 10) : ((c >= 'A' && c <= 'F') ? (c - 'A' + 10) : -1)
                ) : -1);
        if (t < 0) break; // Error
        if (r > ((positive ? 2147483647 : 2147483648) - t) / radix) {
            overflow = true;
        }
        r = r * radix + t;
    }
    
    if (overflow) return (positive ? 2147483647 : -2147483648);
    return positive ? r : -r;
}

void test_myAtoi()
{
    printf("%d\n", myAtoi("0"));
    printf("%d\n", myAtoi("1"));
    printf("%d\n", myAtoi("+19"));
    printf("%d\n", myAtoi("19e"));
    printf("%d\n", myAtoi("-19"));
    printf("%d\n", myAtoi("999999999999999"));
    printf("%d\n", myAtoi("0xfAeC12"));
    printf("%d\n", myAtoi("08"));
    printf("%d\n", myAtoi("010"));
    printf("%d\n", myAtoi("016"));
    printf("%d\n", myAtoi("2147483646"));
    printf("%d\n", myAtoi("2147483647"));
    printf("%d\n", myAtoi("2147483648"));
    printf("%d\n", myAtoi("-2147483647"));
    printf("%d\n", myAtoi("-2147483648"));
    printf("%d\n", myAtoi("-2147483649"));
    printf("%d\n", myAtoi("    010"));
    printf("%d\n", myAtoi("    10522545459"));
}
