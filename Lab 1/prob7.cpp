#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,tg;
    cin>>n>>tg;
    int arr[n];
    
    for(auto &x:arr)
    {
        cin>>x;
    }
    int ind1[1000]={0};
    int ind2[1000]={0};
    for(int i=0;i<n;i++)
    {
        if(!ind1[arr[i]])
        {
            ind1[arr[i]]=i;
        }
        else
        {
            ind2[arr[i]]=i;
        }

    }
    /*for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    */
    sort(arr,arr+n);
    int x,y;
    bool ok=false;
    int i=0,j=n-1;
    for(auto &x:arr)
    cout<<x<<endl;
    while(i<j)
    {
        if(arr[i]+arr[j]>tg)
        j--;
        else if(arr[i]+arr[j]<tg)
        i++;
        else
        {
            ok=true;
            if(arr[i]==arr[j])
            {
            x=ind1[arr[i]];
            y=ind2[arr[j]];
            }
            else
            {
            x=ind1[arr[i]];
            y=ind1[arr[j]];    
            }
            break;
        }
    }
    
    if(ok)
    {
        cout<<"YES"<<endl;
        cout<<x+1<<endl;
        cout<<y+1<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

}