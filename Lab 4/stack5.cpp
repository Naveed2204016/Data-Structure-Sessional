#include<bits/stdc++.h>
using namespace std;
void toh(int n,char a,char b,char c)
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        cout<<"move one dice from "<<a<<" "<<" to "<<c<<endl;
        toh(n-1,b,a,c);
    }
}
int main()
{
    int n;
    cin>>n;
    char a='A',b='B',c='C';
    toh(3,a,b,c);
}