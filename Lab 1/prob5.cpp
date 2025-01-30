#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n];
        for(auto &x:a) cin>>x;
        for(auto &x:b) cin>>x;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(2*a[i]<b[i])
            {

            }
            else if(2*b[i]<a[i])
            {

            }
            else
            ans++;
        }
        cout<<ans<<endl;
    }
}