/*
problem:- Ninja's Trip 
problem:- 983. Minimum Cost For Tickets
link1:- https://leetcode.com/problems/minimum-cost-for-tickets/
link2:- https://www.codingninjas.com/codestudio/problems/minimum-coins_2180776
*/

/*int solveRec(int n, vector<int> days, vector<int> cost,int index)
{
    //Base case
    if(index>=n)
    {
        return 0;
    }
    // 1 day pass
    int option1=cost[0]+solveRec(n,days,cost,index+1);
    // 7 Days pass
    int i;
    for(i=index; i<n and days[i]<days[index]+7; i++);
    int option2=cost[1]+solveRec(n,days,cost,i);
    // 30 Days pass
    for(i=index; i<n and days[i]<days[index]+30; i++);
    int option3=cost[2]+solveRec(n,days,cost,i); 
    int ans=min(option1,min(option2,option3));
    return ans; 
}*/
/*int solveMem(int n, vector<int> days, vector<int> cost,int index,vector<int>&dp)
{
    //Base case
    if(index>=n)
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    // 1 day pass
    int option1=cost[0]+solveMem(n,days,cost,index+1,dp);
    // 7 Days pass
    int i;
    for(i=index; i<n and days[i]<days[index]+7; i++);
    int option2=cost[1]+solveMem(n,days,cost,i,dp);
    // 30 Days pass
    for(i=index; i<n and days[i]<days[index]+30; i++);
    int option3=cost[2]+solveMem(n,days,cost,i,dp); 
    dp[index]=min(option1,min(option2,option3));
    return dp[index]; 
}*/
int solvedp(int n, vector<int> days, vector<int> cost)
{

    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;

    for(int k=n-1; k>=0; k--)
    {
        // 1 day pass
        int option1=cost[0]+dp[k+1];
        // 7 Days pass
        int i;
        for(i=k; i<n and days[i]<days[k]+7; i++);
        int option2=cost[1]+dp[i];
        // 30 Days pass
        for(i=k; i<n and days[i]<days[k]+30; i++);
        int option3=cost[2]+dp[i]; 
        dp[k]=min(option1,min(option2,option3));
    }
    
    return dp[0]; 
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    //return solveRec(n,days,cost,0);
    //vector<int>dp(n+1,-1);
    //return solveMem(n,days,cost,0,dp);
    return solvedp(n, days,cost);
}