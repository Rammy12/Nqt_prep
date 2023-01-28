#include<bits/stdc++.h>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,int>m;
    m.insert(make_pair("mango",100));
    m["Banana"]=20;
    pair<string,int>p;
    p.first="Apple";
    p.second=120;
    m.insert(p);

    //searching
    string f;
    cin>>f;
    auto it=m.find(f);
    if(it!=m.end())
    {
        cout<<"Price of "<<f<<"Is "<<m[f]<<endl;
    }
    else{
        cout<<"Fruit is not present"<<endl;
    }
    //erase
    m.erase(f);
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<"and "<<it->second<<endl;
    }
    for(auto x:m)
    {
        cout<<it->first<<"and "<<it->second<<endl;
    }

    return 0;
}