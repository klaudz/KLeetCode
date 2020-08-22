//
//  9_palindrome_number.c
//  KLeetCode
//
//  Created by klaudz on 11/27/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"

bool isPalindrome(int x) {
    
    int y = 0;
    int t = x;
    while (t > 0) {
        y = y * 10 + t % 10;
        t /= 10;
    }
    return (x == y);
}

int main(void)
{
    {
        int x = 121;
        printf("%d %d\n", x, isPalindrome(x));
    } {
        int x = 122;
        printf("%d %d\n", x, isPalindrome(x));
    } {
        int x = 1221;
        printf("%d %d\n", x, isPalindrome(x));
    } {
        int x = 12210;
        printf("%d %d\n", x, isPalindrome(x));
    } {
        int x = 1;
        printf("%d %d\n", x, isPalindrome(x));
    } {
        int x = 0;
        printf("%d %d\n", x, isPalindrome(x));
    }
    
}
