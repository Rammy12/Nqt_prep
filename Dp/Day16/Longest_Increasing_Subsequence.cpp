/*
problem:- Longest Increasing Subsequence
link:- https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
*/

class Solution
{
    public:
    /*int solveRec(int n,int a[],int curr,int prev)
    {
        //base case
        if(curr==n)
        {
            return 0;
        }
        int include=0;
        //include 
        if(prev==-1 or a[curr]>a[prev])
        {
            include=1+solveRec(n,a,curr+1,curr);
        }
        int exclude=0+solveRec(n,a,curr+1,prev);
        return max(include,exclude);
    }*/
    /*int solveMem(int n,int a[],int curr,int prev,vector<vector<int>>&dp)
    {
        //base case
        if(curr==n)
        {
            return 0;
        }
        if(dp[curr][prev+1]!=-1)
        {
            return dp[curr][prev+1];
        }
        int include=0;
        //include 
        if(prev==-1 or a[curr]>a[prev])
        {
            include=1+solveMem(n,a,curr+1,curr,dp);
        }
        int exclude=0+solveMem(n,a,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);
    }*/
    /*int solvedp(int n,int a[])
    {
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                int include=0;
                //include 
                if(prev==-1 or a[curr]>a[prev])
                {
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=0+dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }*/
    //space optimization
    /*int solvedp(int n,int a[])
    {
        vector<int>currV(n+1,0);
        vector<int>next(n+1,0);
        for(int curr=n-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                int include=0;
                //include 
                if(prev==-1 or a[curr]>a[prev])
                {
                    include=1+next[curr+1];
                }
                int exclude=0+next[prev+1];
                currV[prev+1]=max(include,exclude);
                next=currV;
            }
        }
        return next[0];
    }*/
    int solveoptimal(int n,int a[])
    {
        if(n==0)
        {
            return 0;
        }
        vector<int>ans;
        ans.push_back(a[0]);
        for(int i=1; i<n; i++)
        {
            if(a[i]>ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //return solveRec(n,a,0,-1);
       //vector<vector<int>>dp(n,vector<int>(n+1,-1));
       //return solveMem(n,a,0,-1,dp);
       //return solvedp(n,a);
       return solveoptimal(n,a);
    }
};