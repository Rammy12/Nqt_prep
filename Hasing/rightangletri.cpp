#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int rightangletriangle(vector<vector<int>>arr,int x,int y)
{
    unordered_map<int,int>xcount;
    unordered_map<int,int>ycount;
    int n=arr.size();
    for(int i=0; i<n; i++)
    {
        xcount[arr[i][0]]++;
        ycount[arr[i][1]]++;
    }
    return (xcount[x]-1)*(ycount[y]-1);
}
int main()
{
    vector<vector<int>>arr{
        {1, 2},
        {1, 4},
        {1, 8},
        {1,9},
        {3,5},
        {4,5},
        {7,5}
    };
    int ans=rightangletriangle(arr,1,5);
    cout<<ans;
    return 0;
}