/*
problem:- 1824 Minimum Sideway Jumps
link:- https://leetcode.com/problems/minimum-sideway-jumps/description/
*/


class Solution {
public:
/*int solveRec(vector<int>& obstacles,int currlen,int currpos)
{
    int n=obstacles.size()-1;
    //base case
    if(currpos==n)
    {
        return 0;
    }
    if(obstacles[currpos+1]!=currlen)
    {
        return solveRec(obstacles,currlen,currpos+1);
    }
    else
    {
        ///side ways jump
        int ans=INT_MAX;
        for(int i=1; i<=3; i++)
        {
            if(currlen!=i and obstacles[currpos]!=i)
            {
                ans=min(ans,1+solveRec(obstacles,i,currpos));
            }
            
        }
        return ans;
    }

}*/
/*int solveMem(vector<int>& obstacles,int currlen,int currpos,vector<vector<int>>&dp)
{
    int n=obstacles.size()-1;
    //base case
    if(currpos==n)
    {
        return 0;
    }
    if(dp[currlen][currpos]!=-1)
    {
        return dp[currlen][currpos];
    }
    if(obstacles[currpos+1]!=currlen)
    {
        return solveMem(obstacles,currlen,currpos+1,dp);
    }
    else
    {
        ///side ways jump
        int ans=INT_MAX;
        for(int i=1; i<=3; i++)
        {
            if(currlen!=i and obstacles[currpos]!=i)
            {
                ans=min(ans,1+solveMem(obstacles,i,currpos,dp));
            }
            
        }
        dp[currlen][currpos]= ans;
        return dp[currlen][currpos];
    }
}*/
int solveDp(vector<int>& obstacles)
{
    int n=obstacles.size()-1;
    vector<vector<int>>dp(4,vector<int>(obstacles.size(),1e9));
    dp[0][n]=0;
    dp[1][n]=0;
    dp[2][n]=0;
    dp[3][n]=0;
    for(int pos=n-1; pos>=0; pos--)
    {
        for(int len=1; len<=3; len++)
        {
            if(obstacles[pos+1]!=len)
            {
                dp[len][pos]=dp[len][pos+1];
            }
            else
            {
                ///side ways jump
                int ans=1e9;
                for(int i=1; i<=3; i++)
                {
                    if(len!=i and obstacles[pos]!=i)
                    {
                        ans=min(ans,1+dp[i][pos+1]);
                    }
                }
                dp[len][pos]= ans;
            }
        }
    }
    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));

}
    int minSideJumps(vector<int>& obstacles) {
        //return solveRec(obstacles,2,0);
        //int n=obstacles.size();
        //vector<vector<int>>dp(4,vector<int>(n+1,-1));
        //return solveMem(obstacles,2,0,dp);
        return solveDp(obstacles);
    }
};