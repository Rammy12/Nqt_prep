/*
problem:- Count Derangements
problem link:- https://www.codingninjas.com/codestudio/problems/count-derangements_1199092
*/
#include <bits/stdc++.h>
#define mod 1000000007
//Using Recursion
/*long long int solveRec(int n)
{
  if(n==1)
  {
    return 0;
  }
  if(n==2){
    return 1;
  }
  return ((n-1)%mod)*((solveRec(n-2)%mod)+(solveRec(n-1)%mod))%mod;
}*/
//Using Memoization
/*long long int solveMem(int n,vector<long long int>&dp)
{
  if(n==1)
  {
    return 0;
  }
  if(n==2){
    return 1;
  }
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  dp[n]= (((n-1)%mod)*((solveMem(n-2,dp)%mod)+(solveMem(n-1,dp)%mod))%mod);
  return dp[n];
}*/
//Using Dp
long long int solveTab(int n)
{
  vector<int>dp(n+1,0);
  dp[1]=0;
  dp[2]=1;
  for(int i=3; i<=n; i++)
  {
    long long int first=dp[i-1]%mod;
    long long int second=dp[i-2]%mod;
    dp[i]=((i-1)%mod)*(first+second)%mod;
  }
  return dp[n];
}
long long int countDerangement(int n) {
  // Write your code here.
  //long long int ans=solveRec(n);
  //return ans;
  //vector<long long int>dp(n+1,-1);
  long long int ans=solveTab(n);
  return ans;

}