/*
Given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total 
value in the knapsack. In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent 
values and weights associated with N items respectively. Also given an integer W which represents knapsack 
capacity, find out the maximum value subset of val[] such that the sum of the weights of this subset is smaller 
than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property)
*/

// Using Recursion Memoization
#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
//Memoization
/*Let us consider constrain n<=100
                           w<=1000
*/
//dp matrix
int t[102][1002];
           
int knapsack(vector<int>wt,vector<int>val,int w,int n)
{
    memset(t,-1,sizeof(t));
    //base case
    if(n==0 or w==0)
    {
        return 0;
    }
    if(t[n][w]!=-1)
    {
        return t[n][w];
    }
    //choice daigram
    if(wt[n-1]>w)
    {
        return t[n][w]=knapsack(wt,val,w,n-1);
    }
    else{
        return t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
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