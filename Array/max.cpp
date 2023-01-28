#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement: Given an array, we have to find the largest element in the array.

Examples:

Example 1:
Input: arr[] = {2,5,1,3,0};
Output: 5
Explanation: 5 is the largest element in the array. 

Example2: 
Input: arr[] = {8,10,5,7,9};
Output: 10
Explanation: 10 is the largest element in the array. 
*/
int maxarr2(vector<int>arr)
{
    int max=arr[0];
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;
    // Second Approach
    // Time Complaxity O(n)
}
int maxarr1(vector<int>arr)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    return arr[n-1];
    // First Approach
    // Time Complaxity O(nlogn)
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int m=maxarr1(arr);
    int m2=maxarr2(arr);
    cout<<"largest Element is :"<<m<<endl;
    cout<<"largest Element is :"<<m2;
    return 0;
}