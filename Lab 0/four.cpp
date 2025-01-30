#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool ok=true;
    for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--)
    {
        if(s[i]!=s[j])
        {
            ok=false;
            break;
        }
    }
    if(ok)
    cout<<"Palindrome"<<endl;
    else
    cout<<"Not palindrome"<<endl;
}