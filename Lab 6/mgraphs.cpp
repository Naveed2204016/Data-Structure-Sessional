#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<bool> vis(N,false);
void dfs(int vertex,vector<int> g[])
{
    vis[vertex]=true;
    cout<<vertex<<" ";
    for(auto child:g[vertex])
    {
        if(vis[child]) continue;
        dfs(child,g);
    }
}

void bfs(int source,vector<int> g[])
{
    queue<int> q;
    vis[source]=true;
    q.push(source);
    while(!q.empty())
    {
        int par=q.front();
        cout<<par<<" ";
        q.pop();
        for(auto child:g[par])
        {
            if(vis[child]) continue;
            vis[child]=true;
            q.push(child);
        }
    }
}
int main()
{
    vector<int> g[N];
    int e;
    cin>>e;
    map<int,int> hsh;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        hsh[a]=1,hsh[b]=1;
    }
    for(int i=1;i<N;i++)
    {
    if(!vis[i] && hsh[i])
    dfs(i,g);
    }
    for(int i=0;i<N;i++) vis[i]=false;
    cout<<endl;
    for(int i=1;i<N;i++)
    {
    if(!vis[i] && hsh[i])
    bfs(i,g);
    }
}