#include<bits/stdc++.h>
using namespace std;
/*
Problem Statement: You are given an array. The task is to reverse the array and print it. 

Examples:

Example 1:
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

Example 2:
Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.
*/
void print(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void Reverse(vector<int>&arr)
{
    int n=arr.size();
    int j=n-1;
    int i=0;
    while(i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        j--;
        i++;
    }
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
    Reverse(arr);
    print(arr);
    
    return 0;
}