/*
problem:-Maximum sum of non-adjacent elements
problem link:- https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
*/
#include<iostream>
#include<vector>
using namespace std;
//Recursion
/*int solve1(vector<int> &nums,int i)
{
    if(i<0)
    {
        return 0;
    }
    if(i==0)
    {
        return nums[0];
    }
    return max(nums[i]+solve1(nums,i-2),solve1(nums,i-1));
}*/
//Recursion+Memoization
/*int solve2(vector<int> &nums,int i,vector<int>&dp)
{
    if(i<0)
    {
        return 0;
    }
    if(i==0)
    {
        return nums[0];
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    dp[i]=max(nums[i]+solve2(nums,i-2,dp),solve2(nums,i-1,dp));
    return dp[i];
}*/
//Dp
/*int solve3(vector<int> &nums,int i)
{
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1; i<n; i++)
    {
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]+0);
    }
    return dp[n-1];
}*/
//space optimization
int solve4(vector<int> &nums)
{
    int n=nums.size();
    int prev2=0;
    int prev1=nums[0];
    for(int i=1; i<n; i++)
    {
        int ans=max(nums[i]+prev2,prev1+0);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    //vector<int>dp(n,-1);
    //return solve2(nums,n-1,dp);
    //return solve1(nums,n);
    return solve4(nums);
    
}
int main()
{
    int n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans=maximumNonAdjacentSum(arr);
    cin>>ans;
    return 0;
}