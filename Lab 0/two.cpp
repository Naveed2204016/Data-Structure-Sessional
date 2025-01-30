#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--)
    {
        char a=s[i];
        s[i]=s[j];
        s[j]=a;
    }
    cout<<s<<endl;
}