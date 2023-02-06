/*
problem:- Combination Sum IV
link:- https://www.codingninjas.com/codestudio/problems/combination-sum-iv_3755252
*/

#include <bits/stdc++.h> 
/*int solveRec(vector<int> &num, int tar)
{
    int n=num.size();
    if(tar==0)
    {
        return 1;
    }
    if(tar<0)
    {
        return 0;
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=solveRec(num,tar-num[i]);
    }
    return ans;
}*/
/*int solveMem(vector<int> &num, int tar,vector<int>&dp)
{
    int n=num.size();
    if(tar==0)
    {
        return 1;
    }
    if(tar<0)
    {
        return 0;
    }
    if(dp[tar]!=-1)
    {
        return dp[tar];
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=solveMem(num,tar-num[i],dp);
    }
    dp[tar]=ans;
    return dp[tar];
}*/

int solvedp(vector<int> &num, int tar)
{
    vector<int>dp(tar+1,0);
    int n=num.size();
    if(tar==0)
    {
        return 1;
    }
    dp[0]=1;
    int ans=0;
    for(int i=1; i<=tar; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-num[j]>=0)
            {
                dp[i]+=dp[i-num[j]];
            }
            
        }
    }
    return dp[tar];
    
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    //vector<int>dp(tar+1,-1);
    //return solveRec(num,tar);
    //return solveMem(num, tar,dp);
    return solvedp(num,tar);
}