#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

bool subbarray0sum(vector<int>arr)
{
    int n=arr.size();
    int presum=0;
    unordered_set<int>s;
    for(int i=0; i<n; i++)
    {
        presum+=arr[i];
        if(presum==0 or s.find(presum)!=s.end())
        {
            return true;
        }
        s.insert(presum);
    
    }
    return false;
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
    if(subbarray0sum(arr)==true)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}