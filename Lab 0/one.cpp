#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100],b[100],c[100];
    cin>>a>>b;
    int j=0;
    for(int i=0;a[i]!='\0';i++)
    {
        c[j]=a[i];
        j++;
    }

    for(int i=0;b[i]!='\0';i++)
    {
        c[j]=b[i];
        j++;
    }
    c[j]='\0';
    for(int i=0;c[i]!='\0';i++)
    {
        cout<<c[i];
    }
    cout<<endl;
}