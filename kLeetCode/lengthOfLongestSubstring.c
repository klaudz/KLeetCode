//
//  lengthOfLongestSubstring.c
//  kLeetCode
//
//  Created by klaudz on 11/19/16.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "lengthOfLongestSubstring.h"

int lengthOfLongestSubstring(char *s) {
    
    int maxLength = 0;
    int i = 0, j = 0;
    while (s[j] != 0) {
        if (i == j) {
            j++;
        } else if (s[i] == s[j]) {
            int length = j - i;
            char *substring = malloc(sizeof(char) * (length + 1));
            memcpy(substring, s+i, length);
            substring[length] = 0;
            printf("%s\n", substring);
            if (length > maxLength) maxLength = length;
            i++;
        } else {
            j++;
        }
    }
    return maxLength;
}

void test_lengthOfLongestSubstring()
{
//    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
//    printf("%d\n", lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));
}
