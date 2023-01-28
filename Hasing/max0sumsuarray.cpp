#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subarraymaxlen(vector<int>arr)
{
    int n=arr.size();
    int presum=0;
    int len=0;
    unordered_map<int,int>ump;
    for(int i=0; i<n; i++)
    {
        presum+=arr[i];
        if(presum==0)
        {
            len=max(len,i+1);
        }
        if(ump.find(presum)!=ump.end())
        {
            len=max(len,i-ump[presum]);
        }
        else{
            ump[presum]=i;
        } 
    }
    return len;
}
int main()
{
    int n;
    cout<<"Enter the size of vector:"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ans=subarraymaxlen(arr);
    cout<<ans;
    return 0;
}
    