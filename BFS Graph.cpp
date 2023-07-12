#include <bits/stdc++.h>
using namespace std;
const int edge = 7;
const int vertex = 6;
vector<int> adjlist[vertex];
bool visited[vertex];
void bfs(int sourc_node);
int main()
{
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[v].push_back(u);
        adjlist[u].push_back(v);
    }
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j : adjlist[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    bfs(5);
    return 0;
}
void bfs(int sourc_node)
{
    queue<int> q;
    q.push(sourc_node);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << " ";
        visited[top] = true;
        for (int child : adjlist[top])
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
    }
}
