#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>*(*(arr+i)+j);
        }
    }
    for(int i=0,j=n-1;i<n/2;i++,j--)
    {
        int temp=*(*(arr+i)+i);
        *(*(arr+i)+i)=*(*(arr+j)+j);
        *(*(arr+j)+j)=temp;
    }

    for(int i=0,k=m-1,j=n-1,l=0;i<n/2;i++,k--,j--,l++)
    {
        int temp=*(*(arr+i)+k);
        *(*(arr+i)+k)=*(*(arr+j)+l);
        *(*(arr+j)+l)=temp;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<*(*(arr+i)+j)<<" ";
        }
        cout<<endl;
    }
}