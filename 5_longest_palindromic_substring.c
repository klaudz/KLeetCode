//
//  5_longest_palindromic_substring.c
//  KLeetCode
//
//  Created by klaudz on 25/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"

char *longestPalindrome(char *s) {
    
    if (s == NULL) return NULL;
    //if (s[0] == 0) return "";
    
#define length(_lr, _even) (_lr * 2 - 1 + _even)
    
    int i = 0;
    int imax = 0;
    int lrmax = 0; // Maximum repetitive length
    int even = 1;
    while (s[i] != 0) {
        // Odd
        int lr = 1;
        int e = 0;
#define ostart (i - lr)
#define oend (i + lr)
        while (ostart >= 0 && s[oend] != 0 && s[ostart] == s[oend]) {
            lr++;
        }
        if (length(lr, e) > length(lrmax, even)) { lrmax = lr; imax = i; even = e; }
        // Even
        lr = 0;
        e = 1;
#define estart (i - lr)
#define eend (i + lr + 1)
        while (estart >= 0 && s[eend] != 0 && s[estart] == s[eend]) {
            lr++;
        }
        if (length(lr, e) > length(lrmax, even)) { lrmax = lr; imax = i; even = e; }
        
        i++;
    }
    int lmax = length(lrmax, even);
    char *ps = malloc(sizeof(char)*(lmax+1));
    memcpy(ps, s+imax-lrmax+1, lmax);
    ps[lmax] = 0;
    return ps;
}

int main(void)
{
    printf("%s\n", longestPalindrome("babad"));
    printf("%s\n", longestPalindrome("cbbd"));
    printf("%s\n", longestPalindrome(""));
    printf("%s\n", longestPalindrome("a"));
    printf("%s\n", longestPalindrome("aa"));
}
