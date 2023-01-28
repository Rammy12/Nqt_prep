#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
string find_window(string s,string pat)
{
    int sl=s.length();
    int pl=pat.length();
    int min_len=INT_MAX;
    int start_ind=-1;
    if(pl>sl)
    {
        return "None";
    }
    int FS[256]={0};
    int FP[256]={0};
    for(int i=0; i<pl; i++)
    {
        char ch=pat[i];
        FP[ch]++;
    }
    int cnt=0;
    int start=0;
    for(int i=0; i<sl; i++)
    {
        char ch=s[i];
        FS[ch]++;
        //maintain cnt of charector
        if(FP[ch]!=0 and FS[ch]<=FP[ch])
        {
            cnt++;
        }
        if(cnt==pl)
        {
            char temp=s[start];
            while(FP[temp]==0 or FS[temp]>FP[temp])
            {
                FS[temp]--;
                start++;
                temp=s[start];
            }
            int window_length=i-start+1;
            if(window_length<min_len)
            {
                min_len=window_length;
                start_ind=start;
            }
        }
        

    }
    if(start_ind==-1)
    {
        return "None";
    }
    string ans=s.substr(start_ind,min_len);
    return ans;
}
int main()
{
    string s="heelloaeo world";
    string p="eelo";
    cout<<find_window(s,p);
    return 0;
}