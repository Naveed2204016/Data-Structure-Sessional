#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> &val,int &sz,int item)
{
    sz++;
    if(sz>=val.size())
    return;
    int index=sz;
    val[index]=item;
    while(index>1)
    {
        int parent=index/2;
        if(val[parent]>val[index])
        {
            swap(val[parent],val[index]);
            index=parent;
        }
        else
        return;
    }
}
void show(vector<int> &val,int &sz)
{
    for(int i=1;i<=sz;i++)
    cout<<val[i]<<" ";
    cout<<endl;
}
int deletehip(vector<int> &val,int &sz)
{
    if(sz==0) return -1;
    if(sz==1)
    {
    sz--;
    return val[1];
    }
    int item=val[1];
    val[1]=val[sz];
    val[sz]=0;
    sz--;
    int index=1,left=2,right=3;
    while(right<=sz)
    {
        if(val[index]<=val[left] && val[index]<=right)
        return item;
        if(val[left]<val[right])
        {
            swap(val[left],val[index]);
            index=left;
        }
        else
        {  
            swap(val[right],val[index]);
            index=right;
        }
        left=2*index;
        right=left+1;
    }
    if(left<=sz)
    {
        if(val[left]<val[index])
        swap(val[left],val[index]);
        index=left;
    }
    return item;
}
int main()
{
    vector<int> val(100);
    int sz=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        insert(val,sz,d);
    }
    show(val,sz);
    vector<int> st(sz);
    int j=0;
    while(sz>0)
    {
        st[j]=deletehip(val,sz);
        j++;
    }
    for(auto &x:st)
    cout<<x<<" ";
    cout<<endl;
    cout<<"insert the item you want to search"<<endl;
    int x; cin>>x;
    int id=lower_bound(st.begin(),st.end(),x)-st.begin();
    if(id<st.size())
    cout<<"ITEM found at "<<id+1<<endl;
    else
    cout<<"Not found"<<endl;
}