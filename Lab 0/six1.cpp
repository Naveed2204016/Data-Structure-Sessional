#include<bits/stdc++.h>
using namespace std;
vector<int> createtemparr(string p)
{
    vector<int> lps(p.size());
    int index=0;
    for(int i=1;i<p.size(); )
    {
        if(p[index]==p[i])
        {
            lps[i]=index+1;
            index++,i++;
        }
        else
        {
            if(index!=0) index=lps[index-1];
            else lps[i]=index,i++;
        }
    }
    return lps;
}

bool kmp(string t,string p)
{
    vector<int> lps=createtemparr(p);
    int i=0,j=0;
    while(i<t.size())
    {
        if(t[i]==p[j])
        {
            i++,j++;
        }
        else
        {
            if(j!=0) j=lps[j-1];
            else i++;
        }

        if(j==p.size())
        {
            return true;
        }
    }

    return false;
}
int main()
{
    string t,p;
    cin>>t>>p;
    if(kmp(t,p))
    cout<<"The pattern exists"<<endl;
    else
    cout<<"The pattern doesnt exists"<<endl;
}