#include <bits/stdc++.h>
using namespace std;
const int vertex = 5;
const int edge = 5;
bool visited[vertex];
int level[vertex] = {};
vector<int> adjacecy_list[vertex];
void BFS(int source_node);
int main()
{
    for (int i = 0; i < vertex; i++)
    {
        int v;
        int u;
        cin >> v >> u;
        adjacecy_list[u].push_back(v);
        adjacecy_list[v].push_back(u);
    }
    cout << "\nthe adjacencyList is\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int child : adjacecy_list[i])
        {
            cout << child << " ";
        }
        cout << "\n";
    }
    cout << "\nthe bfs travers is\n";
    int source_node = 2;
    BFS(source_node);
    cout << "\nthe source is 2\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> " << level[i] << "\n";
    }
    return 0;
}

void BFS(int source_node)
{
    queue<int> q;
    q.push(source_node);
    while (!q.empty())
    {
        int head = q.front();
        visited[head] = true;
        cout << head << " ";
        q.pop();
        for (int child : adjacecy_list[head])
        {
            if (visited[child] == false)
            {
                level[child] = level[head] + 1;
                q.push(child);
                visited[child] = true;
            }
        }
    }
}