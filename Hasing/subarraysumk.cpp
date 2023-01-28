#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subarraymaxlenk(vector<int>arr,int k)
{
    int n=arr.size();
    int presum=0;
    int len=0;
    unordered_map<int,int>ump;
    for(int i=0; i<n; i++)
    {
        presum+=arr[i];
        if(presum==k)
        {
            len=max(len,i+1);
        }
        if(ump.find(presum-k)!=ump.end())
        {
            len=max(len,i-ump[presum-k]+1);
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
    int k;
    cin>>k;
    int ans=subarraymaxlenk(arr,k);
    cout<<ans;
    return 0;
}