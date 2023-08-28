//leetcode question 4
//problem 486. Predict the Winner

#include <stdbool.h>

bool predictTheWinner(int* nums, int numsSize) {
    // Initialize the 2D array to store difference
    int dp[numsSize][numsSize];    
    // Fill diagonal elements
    for (int i = 0; i < numsSize; i++) {
        dp[i][i] = nums[i];
    }    
    for (int len = 2; len <= numsSize; len++) {
        for (int i = 0; i <= numsSize - len; i++) {
            int j = i + len - 1;
            dp[i][j] = fmax(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    } 
    return dp[0][numsSize1 - 1] >= 0;
}
