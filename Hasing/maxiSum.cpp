#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int maxiSubarraylength(vector<int>arr,int k)
{
    int n=arr.size();
    int sum=0;
    int ans=0;
    int i=0;
    int j=0;
    while(j<n)
    {
        sum+=arr[j];
        if(sum==k)
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else if(sum>k)
        {
            while(sum>k)
            {
                sum-=arr[i];
                i++;
            }
            j++;
        }
        else{
            j++;
        }
    }
    return ans;
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
    
    cout<<maxiSubarraylength(arr,sum)<<endl;
    return 0;
}