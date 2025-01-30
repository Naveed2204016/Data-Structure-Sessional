#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr) cin>>x;
    bool ok=true;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            ok=false;
            break;
        }
    }
    if(ok)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
}