#include<bits/stdc++.h>
using namespace std;
stack<int>st;
const int N=100;
int visited[N];
vector<int>adjList[N];
void dfs(int src);
void bfs(int src);
bool x=false;
int main()
{
    int vertex;
    int edge;
    cin>>vertex>>edge;
    for(int i=0; i<N; i++)
    {
        visited[i]=0;
    }
    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
    }
    for(int i=1; i<=vertex; i++)
    {
        if(visited[i]==0)dfs(i);
    }
    if(x==true)cout<< "IMPOSSIBLE";
    else
    {
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }
    return 0;
}
void dfs(int src)
{
    visited[src]=1;
    for(int i:adjList[src])
    {
        if(visited[i]==0)dfs(i);
        if(visited[i]==1)
        {
            x=true;
        }
    }
    visited[src]=2;
    st.push(src);
}