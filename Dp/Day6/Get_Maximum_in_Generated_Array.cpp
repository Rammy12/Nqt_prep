/*
problem:- Leetcode 1646 Get Maximum in Generated Array
problem link:- https://leetcode.com/problems/get-maximum-in-generated-array/
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(n + 1, 0);
        if(n == 0)
            return 0;
        dp[1] = 1;
        int maxi = 1;
	
        for(int i = 2; i <= n; ++i){
            if(i & 1)
                dp[i] = dp[i >> 1] + dp[(i >> 1) + 1];
            else 
                dp[i] = dp[i >> 1];
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};