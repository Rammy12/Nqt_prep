#include<bits/stdc++.h>
using namespace std;
int smallest2(vector<int>arr)
{
    int min=INT_MAX;
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
        }
    }
    return min;
    // Second Approach
    // Time Complaxity O(n)
}
int smallest1(vector<int>arr)
{
    sort(arr.begin(),arr.end());
    return arr[0];
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
    int sm=smallest1(arr);
    int sm2=smallest2(arr);
    cout<<"Smallest Element is :"<<sm<<endl;
    cout<<"Smallest Element is :"<<sm2;
    return 0;
}