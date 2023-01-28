#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int>wt,vector<int>val,int w,int n)
{
    //dp matrix
    int t[n+1][w+1];
    //initilization
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i==0 or j==0)
            {
                t[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    //choice daigram
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i-1][w-wt[i-1]],t[i-1][j]);
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }*/
    return t[n][w];

}
int main()
{
    int n;
    cin>>n;
    vector<int>wt(n);
    vector<int>val(n);
    cout<<"Enter Weight Element"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter Value Element"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>val[i];
    }
    int w;
    cin>>w;
    int ans=knapsack(wt,val,w,n);
    cout<<ans<<endl;
    return 0;
}