#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        while(m--)
        {
            char a; int x,y;
            cin>>a;
            if(a=='P')
            {
                cin>>x>>y;
                int temp=arr[x-1];
                arr[x-1]=arr[y-1];
                arr[y-1]=temp;
            }
            else if(a=='R')
            {
                for(int i=0,j=(sizeof(arr)/sizeof(int))-1;i<(sizeof(arr)/sizeof(int))/2;i++,j--)
                {
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
            else
            {
                cin>>x;
                if(a=='S')
                {
                    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
                    {
                        arr[i]+=x;
                    }
                }
                else if(a=='M')
                {
                    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
                    {
                        arr[i]*=x;
                    }
                }
                else if(a=='D')
                {
                    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
                    {
                        arr[i]/=x;
                    }
                }
            }

            for(int i=0;i<sizeof(arr)/sizeof(int);i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
}