//
//  lengthOfLongestSubstring.c
//  KLeetCode
//
//  Created by klaudz on 11/19/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"

int lengthOfLongestSubstring(char *s) {
    
    int lmax = 0;
    int i = 0, j = 0;
    while (s[j] != 0) {
        int it = i;
        int k = j - 1;
        while (k >= i) {
            if (s[k] == s[j]) {
                int l = j - k;
                if (l > lmax) {
                    lmax = l;
                }
                i = k + 1;
                break;
            }
            k--;
        }
        if (it == i) {
            int l = j - i + 1;
            if (l > lmax) {
                lmax = l;
            }
        }
        j++;
    }
    return lmax;
}

int main(void)
{
    printf("%d\n", lengthOfLongestSubstring(""));
    printf("%d\n", lengthOfLongestSubstring("c"));
    printf("%d\n", lengthOfLongestSubstring("ab"));
    printf("%d\n", lengthOfLongestSubstring("cdd"));
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));
}
