/*
Minimum Elements
problem link: https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/
#include<iostream>
#include<vector>
using namespace std;
//Using Recursion
int solveRecS(vector<int>&arr,int x,vector<int>&dp)
{
    int mini=INT_MAX;
    int n=arr.size();
    //base case
    if(x==0)
    {
        return 0;
    }
    if(x<0)
    {
        return INT_MAX;
    }
    for(int i=0; i<n; i++)
    {
        int ans=solve(arr,x-arr[i],dp);
        if(ans!=INT_MAX)
        {
            mini=min(mini,ans+1);
        }
    }
    return mini;
}
//Using memoization 
int solveMem(vector<int>&arr,int x,vector<int>&dp)
{
    int mini=INT_MAX;
    int n=arr.size();
    //base case
    if(x==0)
    {
        return 0;
    }
    if(x<0)
    {
        return INT_MAX;
    }
    //step 2
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    for(int i=0; i<n; i++)
    {
        int ans=solve(arr,x-arr[i],dp);
        if(ans!=INT_MAX)
        {
            mini=min(mini,ans+1);
        }
    }
    dp[x]=mini;
    return dp[x];
}
//Using Dp
int solveDP(vector<int>&arr,int x)
{
    int n=arr.size();
    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-arr[j]>=0 and dp[i-arr[j]]!=INT_MAX)
            {
                dp[i]=min(dp[i],1+dp[i-arr[j]]);

            }
            
        }

    }
    if(dp[x]==INT_MAX)
    {
        return -1;
    }
    else{
        return dp[x];
    }
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    //step 1
    //vector<int>dp(x+1,-1);
    //int ans=solveMem(num,x,dp);
    //if(ans==INT_MAX)
    //{
    //    return -1;
    //}
     //   return ans;
    return solveDP(num,x);
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
    int x;
    cin>>x;
    int ans=minimumElements(arr,x);
    cout<<ans<<endl;
    return 0;
}