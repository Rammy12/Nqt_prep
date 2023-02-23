/*
problem: Dice throw
link: https://practice.geeksforgeeks.org/problems/dice-throw5349/1
*/



class Solution {
  public:
  /*long long solveRec(int dice , int face , int target)
  {
      //Base case
      long long ans=0;
      if(target<0)
      {
          return 0;
      }
      if(dice==0 and target!=0)
      {
          return 0;
      }
      if(target==0 and dice!=0)
      {
          return 0;
      }
      if(dice==0 && target==0)
      {
          return 1;
      }
      for(int i=1; i<=face; i++)
      {
          ans=ans+solveRec(dice-1,face,target-i);
      }
      return ans;
      
  }*/
  /*long long solveMem(int dice , int face , int target,vector<vector<long long >>&dp)
  {
      //Base case
      long long ans=0;
      if(target<0)
      {
          return 0;
      }
      if(dice==0 and target!=0)
      {
          return 0;
      }
      if(target==0 and dice!=0)
      {
          return 0;
      }
      if(dice==0 && target==0)
      {
          return 1;
      }
      if(dp[dice][target]!=-1)
      {
          return dp[dice][target];
      }
      for(int i=1; i<=face; i++)
      {
          ans=ans+solveMem(dice-1,face,target-i,dp);
      }
      return dp[dice][target]=ans;
      
  }*/
  long long solvetab(int dice , int face , int target)
  {
      vector<vector<long long >>dp(dice+1,vector<long long>(target+1,0));
      dp[0][0]=1;
      for(int d=1; d<=dice; d++)
      {
          for(int t=1; t<=target; t++)
          {
              long long ans=0;
              for(int i=1; i<=face; i++)
                {
                    if(t-i>=0)
                    {
                        ans=ans+dp[d-1][t-i];
                    }
                    
                }
                dp[d][t]=ans;
          }
      }
      return dp[dice][target];
  }
    long long noOfWays(int M , int N , int X) {
        // code here
        //return solveRec(N,M,X);
        //vector<vector<long long >>dp(N+1,vector<long long>(X+1,-1));
        //return solveMem(N,M,X,dp);
        return solvetab(N,M,X);
    }
};