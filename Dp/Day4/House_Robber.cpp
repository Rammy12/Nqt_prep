/*
problem:-House Robber II
problem link:- https://www.codingninjas.com/codestudio/problems/house-rabber_839733
*/
#include<iostream>
#include<vector>
using namespace std;
long long int solve(vector<int> &nums)
{
    long long int n=nums.size();
    long long int prev2=0;
    long long int prev1=nums[0];
    for(int i=1; i<n; i++)
    {
        long long int ans=max(nums[i]+prev2,prev1+0);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1)
    {
        return valueInHouse[0];
    }
    vector<int>first,second;
    for(int i=0; i<n; i++)
    {
        if(i!=0)
        {
            second.push_back(valueInHouse[i]);
        }
        if(i!=n-1)
        {
            first.push_back(valueInHouse[i]);
        }
    }
    return max(solve(first),solve(second));
}
int main()
{
    int n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    long long int ans=houseRobber(arr);
    cin>>ans;
    return 0;
}