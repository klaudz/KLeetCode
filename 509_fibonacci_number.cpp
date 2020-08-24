//
//  509_fibonacci_number.c
//  KLeetCode
//
//  Created by klaudz on 24/8/2020.
//  Copyright © 2020 klaudz. All rights reserved.
//

#include "common/includes.h"
#include <vector>

class Solution {
public:
    int fib(int N) {
#define SOLUTION 1
#if SOLUTION == 0
        return fib_RecursiveDP(N);
#elif SOLUTION == 1
        return fib_IterativeDP(N);
#endif
    }
#pragma mark Recursive DP
    int fib_RecursiveDP(int N) {
        std::vector<int> dp = std::vector<int>(N + 1, -1);
        return fib_RecursiveDP(N, dp);
    }
    int fib_RecursiveDP(int N, std::vector<int> &dp) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        if (N == 2) return 1;
        int val = dp[N];
        if (val != -1) return val;
        val = fib_RecursiveDP(N - 1, dp) + fib_RecursiveDP(N - 2, dp);
        dp[N] = val;
        return val;
    }
#pragma mark Iterative DP
    int fib_IterativeDP(int N) {
        std::vector<int> dp = std::vector<int>(N + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }
};

int main(void)
{
    {
        Solution s = Solution();
        int val = s.fib(0);
        printf("%d\n", val);
    }
    {
        Solution s = Solution();
        int val = s.fib(1);
        printf("%d\n", val);
    }
    {
        Solution s = Solution();
        int val = s.fib(20);
        printf("%d\n", val);
    }
    {
        Solution s = Solution();
        int val = s.fib(30);
        printf("%d\n", val);
    }
    return 0;
}
