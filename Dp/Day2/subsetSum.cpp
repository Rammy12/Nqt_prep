/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with
sum equal to given sum.

Example:-
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/
#include<iostream>
#include<vector>
using namespace std;
bool SubsetSumUsingDp(vector<int>arr,int sum,int n)
{
    //dp matrix
    bool t[n+1][sum+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            if(i==0)
            {
                t[i][j]=false;
            }
            if(sum==0)
            {
                t[i][j]=true;
            }
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i-1][j-arr[i-1]] or t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];

}
bool SubsetSumUsingRecursion(vector<int>arr,int sum,int n)
{
    //base case
    if(n==0)
    {
        return false;
    }
    if(sum==0)
    {
        return true;
    }
    if(arr[n-1]<=sum)
    {
        return SubsetSumUsingRecursion(arr,sum-arr[n-1],n-1) or SubsetSumUsingRecursion(arr,sum,n-1);
    }
    else{
        return SubsetSumUsingRecursion(arr,sum,n-1);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    if(SubsetSumUsingDp(arr,sum,n)==true)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}