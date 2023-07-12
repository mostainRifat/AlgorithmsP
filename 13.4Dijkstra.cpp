#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=100;
vector<pair<int,int>>adja_list[N];
int distaNce[N];
bool visited[N];
void DIJKSTRA(int src);
void dij(int src);
void adj(int src); 
void dijkstra(int src);
int parent[N];
int main()
{
    cin>>n>>m;
    for(int i=0; i<=n; i++)distaNce[i]=100000;
    int src=7;
    distaNce[src]=0;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adja_list[u].push_back({v,w});
        adja_list[v].push_back({u,w});
    }
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" -> ";
        for(auto j: adja_list[i])
        {
            cout<<'('<<j.first<<','<<j.second<<')'<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    dijkstra(src);
    for(int i=1; i<=n; i++)cout<<parent[i]<<" ";
    return 0;
}
void DIJKSTRA(int src)
{
    for(int i=1; i<=n; i++)
    {
        int selectec_node=-1;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]==true)continue;
            if(selectec_node==-1||distaNce[selectec_node]>distaNce[j])
                selectec_node=j;
        }
        visited[selectec_node]=true;
        for(auto j:adja_list[selectec_node])
        {
            if(distaNce[j.first]>distaNce[selectec_node]+j.second)
            {
                distaNce[j.first]=distaNce[selectec_node]+j.second;
            }
        }
    }
}
void dij(int src)
{
    for(int i=0; i<n; i++)
    {
        int selection_node=-1;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]==true)continue;
            if(selection_node==-1|| distaNce[selection_node]>distaNce[j])selection_node=j;
        }
        visited[selection_node]=true;
        for(auto child:adja_list[selection_node])
        {
            if(distaNce[child.first]>distaNce[selection_node]+child.second)
            {
                distaNce[child.first]=distaNce[selection_node]+child.second;
            }
        }
    }
}
void adj(int src)
{
    for(int i=0; i<n; i++)
    {
        int now=-1;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]==true)continue;
            if(now==-1 || distaNce[now]>distaNce[j])
            {
                now=j;
            }
        }
        visited[now]=true;
        for(auto j:adja_list[now])
        {
            if(distaNce[j.first]>distaNce[now]+j.second)
            {
                distaNce[j.first]=distaNce[now]+j.second;
            }
        }
    }
}
void dijkstra(int src)
{
    for(int i=0; i<n; i++)
    {
        int now=-1;
        for(int j=1; j<=n; j++)
        {
            if(visited[j]==true)continue;
            if(now==-1|| distaNce[now]>distaNce[j])
            {
                now=j;
            }
        }
        visited[now]=true;
        for(auto j:adja_list[now])
        {
            if(distaNce[j.first]>distaNce[now]+j.second)
            {
                distaNce[j.first]=distaNce[now]+j.second;
                parent[j.first]=now;
            }
        }
    }
}