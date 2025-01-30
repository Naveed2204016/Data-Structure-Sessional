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

    bool ok=true;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(*(*(arr+i)+j) != -1*(*(*(arr+j)+i)))
            {
                ok=false;
                break;
            }
        }
    }
    
    if(ok)
    cout<<"Skew symmetric"<<endl;
    else
    cout<<"The matrix is not skew-symmetric"<<endl;
    /*
        0 2 4
        -2 0 6
        -4 -6 0    */
}