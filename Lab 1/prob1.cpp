#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n],arr1[m][k];
    for(int i=0;i<n;i++)
    {
        cin>>*(arr+i);
    }

    int *ptr=&arr[0];
    for(int i=0;i<n;i++)
    {
        cout<<*(ptr+i)<<" ";
    }
    
    int *ptr1=&arr1[0][0];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            cin>>*(ptr1+i*m+j);
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            cout<<*(ptr1+i*m+j)<<" ";
        }
        cout<<endl;
    }
}