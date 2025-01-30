#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int hsh[256]={0};
    for(int i=0;i<s.size();i++)
    {
        hsh[s[i]]++;
    }
    
    char ans;
    for(int i=0;i<s.size();i++)
    {
        if(hsh[s[i]]==1)
        {
            ans=s[i];
            break;
        }
    }
    cout<<ans<<endl;

}