#include<bits/stdc++.h>
using namespace std;
int fib(int n,vector<int>dp)
{
    if(n==0 or n==1)
    {
        return n;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans;
    ans=fib(n-1,dp)+fib(n-2,dp);
    return dp[n]=ans;
}
int fibBtU(int n)
{
    vector<int>dp(100,0);
    dp[1]=1;
    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fibspaceopt(int n)
{
    if(n==0 or n==1)
    {
        return n;
    }
    int a=0;
    int b=1;
    int c;
    for(int i=2; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(100);
    int ans=fib(n,dp);
    cout<<ans<<endl;
    cout<<"Bottom Up:- "<<fibBtU(n)<<endl;
    cout<<"Space optimized:- "<<fibspaceopt(n)<<endl;
    return 0;
}