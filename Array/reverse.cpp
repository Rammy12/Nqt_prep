#include<bits/stdc++.h>
using namespace std;
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