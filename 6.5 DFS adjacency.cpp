#include<bits/stdc++.h>
using namespace std;
const int edge=7;
const int vertex=6;
vector<int>adjlist[vertex];
bool visited[vertex];
void dfs(int sourc_node);
int main()
{
    for(int i =0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adjlist[v].push_back(u);
        adjlist[u].push_back(v);
    }
    for(int i=0; i<vertex; i++)
    {
        cout<<i<<" -> ";
        for(int j:adjlist[i])
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    dfs(5);
    return 0;
}
void dfs(int sourc_node)
{
    cout<<sourc_node<<" ";
    visited[sourc_node]=true;
    for(int child:adjlist[sourc_node])
        if(visited[child]==false)
            dfs(child);
}