/*
leetcode 746. Min Cost Climbing Stairs
problem link:- https://leetcode.com/problems/min-cost-climbing-stairs/description/
*/
#include<iostream>
#include<vector>
using namespace std;
//Using memoization +recursion
/*int solve(vector<int>&c,int n,vector<int>&dp)
{
    if(n==0)
    {
        return c[0];
    }
    if(n==1)
    {
        return c[1];
    }
    //step 3
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    //step 2
    dp[n]=c[n]+min(solve(c,n-1,dp),solve(c,n-2,dp));
    return dp[n];
}*/
//Using Bottom UP
int solve2(vector<int>&c,int n)
{
    vector<int>dp(n+1);
    dp[0]=c[0];
    dp[1]=c[1];
    for(int i=2; i<n; i++)
    {
        dp[i]=c[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
}
    int minCostClimbingStairs(vector<int>& cost) {
        /*int n=cost.size();
        //step 1
        vector<int>dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;*/
        int n=cost.size();
        return solve2(cost,n);
        
    }
int main()
{   
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans=minCostClimbingStairs(arr);
    cout<<ans<<endl;
    return 0;
}