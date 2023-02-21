/*
problem: Pizza With 3n Slices
link: https://leetcode.com/problems/pizza-with-3n-slices/description/
*/

class Solution {
public:
/*int solve(int i,vector<int>& slices,int endind,int n)
{
    //base case 
    if(n==0 or  i>endind)
    {
        return 0;
    }
    int take=slices[i]+solve(i+2,slices,endind,n-1);
    int nottake=0+solve(i+1,slices,endind,n);
    return max(take,nottake);
}*/
/*int solveMem(int i,vector<int>& slices,int endind,int n,vector<vector<int>>&dp)
{
    //base case 
    if(n==0 or  i>endind)
    {
        return 0;
    }
    if(dp[i][n]!=-1)
    {
        return dp[i][n];
    }
    int take=slices[i]+solveMem(i+2,slices,endind,n-1,dp);
    int nottake=0+solveMem(i+1,slices,endind,n,dp);
    dp[i][n]=max(take,nottake);
    return dp[i][n];
   
}*/
int solveTab(vector<int>& slices)
{
    int k=slices.size();
    vector<vector<int>>dp1(k+2,vector<int>(k+2,0));
    vector<vector<int>>dp2(k+2,vector<int>(k+2,0));
    //case 1
    for(int i=k-2; i>=0; i--)
    {
        for(int j=1; j<=k/3; j++)
        {
            int take=slices[i]+ dp1[i+2][j-1];
            int nottake=0+dp1[i+1][j];
            dp1[i][j]=max(take,nottake);
        }
    }
    int case1=dp1[0][k/3];
    //case 2
    for(int i=k-1; i>=1; i--)
    {
        for(int j=1; j<=k/3; j++)
        {
            int take=slices[i]+ dp2[i+2][j-1];
            int nottake=0+dp2[i+1][j];
            dp2[i][j]=max(take,nottake);
        }
    }
    int case2=dp2[1][k/3];
    return max(case1,case2);
}
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        /*int case1=solve(0,slices,k-2,k/3);
        int case2=solve(1,slices,k-1,k/3);
        return max(case1,case2);*/
        /*vector<vector<int>>dp1(k,vector<int>(k,-1));
        int case1=solveMem(0,slices,k-2,k/3,dp1);
        vector<vector<int>>dp2(k,vector<int>(k,-1));
        int case2=solveMem(1,slices,k-1,k/3,dp2);
        return max(case1,case2);*/
        return solveTab(slices);
    }
};