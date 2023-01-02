#include<bits/stdc++.h>
using namespace std;
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