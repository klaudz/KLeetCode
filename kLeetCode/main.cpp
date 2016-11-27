//
//  main.cpp
//  kLeetCode
//
//  Created by klaudz on 18/11/2016.
//  Copyright © 2016 klaudz. All rights reserved.
//

#include <iostream>

#include "twoSum.h"
#include "addTwoNumbers.h"
#include "lengthOfLongestSubstring.h"
#include "findMedianSortedArrays.h"
#include "longestPalindrome.h"

#include "reverseInteger.h"
#include "myAtoi.h"
#include "isPalindrome.h"

#include "longestCommonPrefix.h"

#include "swapPairs.h"
#include "reverseKGroup.h"
#include "removeElement.h"

#include "searchRange.h"

#include "firstMissingPositive.h"

int main(int argc, const char * argv[]) {
    
    int n = 9;
    if (argc > 1) {
        n = myAtoi((char *)argv[1]);
    }
    switch (n) {
        case 1:
            test_twoSum();
            break;
        case 2:
            test_addTwoNumbers();
            break;
        case 3:
            test_lengthOfLongestSubstring();
            break;
        case 4:
            test_findMedianSortedArrays();
            break;
        case 5:
            test_longestPalindrome();
            break;
            
        case 7:
            test_reverseInteger();
            break;
        case 8:
            test_myAtoi();
            break;
        case 9:
            test_isPalindrome();
            break;
            
        case 14:
            test_longestCommonPrefix();
            break;
            
        case 24:
            test_swapPairs();
            break;
        case 25:
            test_reverseKGroup();
            break;
        case 27:
            test_removeElement();
            break;
            
        case 34:
            test_searchRange();
            break;
            
        case 41:
            test_firstMissingPositive();
            break;
            
        default:
            printf("Problem (%d) not found\n", n);
            break;
    }
    
    return 0;
}
