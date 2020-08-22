//
//  longestCommonPrefix.c
//  KLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include "common/includes.h"

char *longestCommonPrefix(char **strs, int strsSize) {
    
    if (strsSize == 0) {
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }
    
    int i = 0;
    while (true) {
        char c = strs[0][i];
        if (c == 0) {
            break;
        }
        bool equals = true;
        for (int j = 0; j < strsSize; j++) {
            equals = equals && (c == strs[j][i]);
            if (!equals) break;
        }
        if (!equals) {
            break;
        }
        i++;
    }
    
    char *prefix = malloc(sizeof(char) * (i + 1));
    memcpy(prefix, strs[0], i);
    prefix[i] = 0;
    return prefix;
}

int main(void)
{
    {
        char *strs[] = { "abc" };
        int strsSize = sizeof(strs) / sizeof(char *);
        char *prefix = longestCommonPrefix(strs, strsSize);
        printf("%s\n", prefix);
    }
    {
        char *strs[] = { "abc",
                         "abcd" };
        int strsSize = sizeof(strs) / sizeof(char *);
        char *prefix = longestCommonPrefix(strs, strsSize);
        printf("%s\n", prefix);
    }
    {
        char *strs[] = { "abc",
                         "abcd",
                         "abed" };
        int strsSize = sizeof(strs) / sizeof(char *);
        char *prefix = longestCommonPrefix(strs, strsSize);
        printf("%s\n", prefix);
    }
}
