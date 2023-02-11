/*
problem:- Reducing Dishes
link:- https://leetcode.com/problems/reducing-dishes/description/
*/

class Solution {
public:
/*int solveRec(vector<int>& sati,int index,int time)
{
    //base case
    if(index==sati.size())
    {
        return 0;
    }
    int inclu=sati[index]*(time+1)+solveRec(sati,index+1,time+1);
    int exclu=0+solveRec(sati,index+1,time);
    return max(inclu,exclu);
}*/
/*int solveMem(vector<int>& sati,int index,int time,vector<vector<int>>&dp)
{
    //base case
    if(index==sati.size())
    {
        return 0;
    }
    if(dp[index][time] !=-1)
    {
        return dp[index][time];
    }
    int inclu=sati[index]*(time+1)+solveMem(sati,index+1,time+1,dp);
    int exclu=0+solveMem(sati,index+1,time,dp);
    dp[index][time]=max(inclu,exclu);
    return dp[index][time];
}*/
int solvedp(vector<int>& satisfaction)
{
    int n=satisfaction.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int index=n-1; index>=0; index--)
    {
        for(int time=index; time>=0; time--)
        {
            int inclu=satisfaction[index]*(time+1)+dp[index+1][time+1];
            int exclu=0+dp[index+1][time];
            dp[index][time]=max(inclu,exclu);
        }
    }
    return dp[0][0];
}
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        //return solveRec(satisfaction,0,0);
        //int n=satisfaction.size();
        //vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        //return solveMem(satisfaction,0,0,dp);
        return solvedp(satisfaction);
    }
};