#include<bits/stdc++.h>
using namespace std;
const int N= 100005;
int level[N];
vector<int> ad_jcen[N];
bool visited[N];
int parent[N];
void bfs(int src );
void dfs(int src);

int main()
{
//https://cses.fi/problemset/task/1667
    int n;
    int m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        ad_jcen[u].push_back(v);
        ad_jcen[v].push_back(u);
    }
    level[n]=-1;

    //bfs(1);
    //level[1]=1;// for dfs we have to initialaize the level of source node
    dfs(1);

    if(level[n]==-1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<level[4]<<"\n";
//    int now=n;
//    stack<int> st;
//    st.push(now);
//    while(st.top()!=1)
//    {
//
//        now=parent[now];
//        st.push(now);
//    }
//
//    while(!st.empty())
//    {
//        cout<<st.top()<<" ";
//        st.pop();
//    }
    return 0;
}
//void bfs(int src )
//{
//    level[src]=1;
//    visited[src]=true;
//    queue<int>q;
//    q.push(src);
//    while(!q.empty())
//    {
//        int head=q.front();
//        q.pop();
//        for(int child:ad_jcen[head])
//        {
//            if(visited[child]==false)
//            {
//                visited[child]=true;
//                level[child]=level[head]+1;
//                parent[child]=head;
//                q.push(child);
//            }
//        }
//    }
//}
void dfs(int src)
{
    visited[src]=true;
    for(int child:ad_jcen[src])
    {
        if(visited[child]==false)
        {
            vector<int>a;
            for(int sub_child:ad_jcen[child])
            {
                if(visited[sub_child]==true)
                {
                    a.push_back(level[sub_child]);
                }
            }
                int  min_value = *min(a.begin(),a.end());
                level[child]=min_value +1;
                dfs(child);
        }
    }
}