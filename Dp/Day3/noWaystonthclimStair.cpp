/*

Count Ways To Reach The N-th Stairs
problem link;=:- https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/
#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
int solve(int n,int i,vector<int>&dp)
{
    if(i==n)
    {
        return 1;
    }
    if(i>n)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    dp[i]= (solve(n,i+1,dp)+solve(n,i+2,dp))%mod;
    return dp[i];
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    vector<int>dp(nStairs+1,-1);
    int ans =solve(nStairs,0,dp);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int ans=countDistinctWays(n);
    cout<<ans<<endl;
    return 0;
}