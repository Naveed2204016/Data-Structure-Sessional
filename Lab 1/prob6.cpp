#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr) cin>>x;
    int fs,ls,m,x;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            fs=arr[i];
            m=i;
            break;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            ls=arr[i];
            x=i;
            break;
        }
    }
    
    cout<<1<<endl;
    cout<<fs<<endl;
    cout<<1<<endl;
    cout<<ls<<endl;
    cout<<n-2<<endl;
    for(int i=0;i<n;i++)
    {
        if(i!=m && i!=x)
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}