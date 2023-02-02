/*
problem :- Leetcode 198 House Robber
problem link:- https://leetcode.com/problems/house-robber/
*/

class Solution {
public:
// Using Recursion
/*int solveRec(vector<int>& nums,int n)
{
    if(n==0)
    {
        return nums[0];
    }
    if(n<0)
    {
        return 0;
    }
    return max(nums[n]+solve(nums,n-2),solve(nums,n-1));
}*/
// Using Memoisation
int solveMem(vector<int>& nums,int n,vector<int>&dp)
{
    if(n==0)
    {
        return nums[0];
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n]= max(nums[n]+solveMem(nums,n-2,dp),solveMem(nums,n-1,dp));
    return dp[n];
}

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solveMem(nums,n-1,dp);
    }
};