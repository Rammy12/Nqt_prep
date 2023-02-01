/*
problem:- Cut Into Segments
problem link:- https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651
*/

#include<limits.h>
#include <vector>
// Recursive+Memoization
/*int solve1(int n, int x, int y, int z,vector<int>&dp)
{
	if(n==0)
	{
		return 0;
	}
	if(n<0)
	{
		return INT_MIN;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	dp[n]= max(solve1(n-x,x,y,z,dp)+1,max(solve1(n-y,x,y,z,dp)+1,solve1(n-z,x,y,z,dp)+1));
	return dp[n];
}*/
//Dp
int solve2(int n, int x, int y, int z)
{
	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1; i<=n; i++)
	{
		if(i-x>=0)
		{
			dp[i]=max(dp[i],dp[i-x]+1);
		}
		if(i-y>=0)
		{
			dp[i]=max(dp[i],dp[i-y]+1);
		}
		if(i-z>=0)
		{
			dp[i]=max(dp[i],dp[i-z]+1);
		}
	}
	if(dp[n]<0)
	{
		return 0;
	}
	    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	/*vector<int>dp(n+1,-1);
	int ans=solve1(n,x,y,z,dp);
	if(ans<0)
	{
		return 0;
	}
	else{
		return ans;
	}*/
	return solve2(n,x,y,z);
}