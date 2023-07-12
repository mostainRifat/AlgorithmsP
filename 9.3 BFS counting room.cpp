#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2002;
bool visited[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool insidethemaze(pair<int,int>src);
void Dfs(pair<int,int>src);
void bfs(pair<int,int>src)
{
    queue<pair<int,int>>q;
    visited[src.first][src.second]=true;
    q.push(src);
    while(!q.empty())
    {
        pair<int,int>head;
        head=q.front();
        q.pop();
        int x=head.first;
        int y=head.second;
        for(int i=0; i<4; i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            pair<int,int>ad_node= {new_x,new_y};
            if(insidethemaze(ad_node)&&visited[new_x][new_y]==0)
            {
                visited[new_x][new_y]=1;
                q.push(ad_node);
            }
        }
    }
}
bool insidethemaze(pair<int,int>src)
{
    if(src.first>=0&&src.first<n&&src.second<m&&src.second>=0)return true;
    return false;
}
int main()
{
    cin>>n;
    cin>>m;
    pair<int,int> src;
    for(int i=0; i<n; i++)
    {
        string input;
        cin >> input;
        for(int j=0; j<m; j++)
        {
            if(input[j]=='#')
                visited[i][j]=true;
        }
    }
    int call=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visited[i][j]==false)
            {
                call++;
                src= {i,j};
                Dfs(src);
            }
        }
    }
    cout<<call;
    return 0;
}
void Dfs(pair<int,int>src)
{
    visited[src.first][src.second]=true;
    int x=src.first;
    int y=src.second;
    for(int i=0; i<4; i++)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        pair<int,int>ad_node= {new_x,new_y};
        if(insidethemaze(ad_node)&&visited[new_x][new_y]==0)
        {
            Dfs(ad_node);
        }
    }
}