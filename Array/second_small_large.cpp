#include<bits/stdc++.h>
using namespace std;
int secondsmall(vector<int>arr)
{
    int n=arr.size();
    if(n<2)
    {
        return -1;
    }
    int small=INT_MAX;
    int second_small=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(small>arr[i])
        {
            second_small=small;
            small=arr[i];
        }
        else if(second_small>arr[i] and small!=arr[i])
        {
            second_small=arr[i];
        }
    }
    return second_small;
}
int secondlarge(vector<int>arr)
{
    int n=arr.size();
    if(n<2)
    {
        return -1;
    }
    int large=INT_MIN;
    int second_large=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(large<arr[i])
        {
            second_large=large;
            large=arr[i];
        }
        else if(second_large<arr[i] and large!=arr[i])
        {
            second_large=arr[i];
        }
    }
    return second_large;
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
    int m=secondlarge(arr);
    int m2=secondsmall(arr);
    cout<<"Second largest Element is :"<<m<<endl;
    cout<<"Second Smallest Element is :"<<m2;
    return 0;
}