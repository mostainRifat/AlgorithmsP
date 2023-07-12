
#include <bits/stdc++.h>
using namespace std;
const int vertex =6;
vector<int> adjenlist[vertex];
bool visited[vertex];
void BFS(int source_node);
void DFS(int source_node)
{
    cout<<source_node<<" ";
    visited[source_node]=true;
    for(int adj_node:adjenlist[source_node])
    {

        if(visited[adj_node]==false)
        {
            DFS(adj_node);
        }
    }
}
int main()
{
    int edge = 6;
    for (int i = 0; i < edge; i++)
    {
        int v;
        int u;
        cin >> v >> u;
        adjenlist[v].push_back(u);
        adjenlist[u].push_back(v);
    }
    cout << "the adjacencyList is"
         << "\n";
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (auto j : adjenlist[i])
            cout << j << " ";
        cout << "\n";
    }
    int sourc_node;
    cout << "source node->";
    cin >> sourc_node;
    DFS(sourc_node);

    return 0;
    /*
    [0]----[1]----[2]----[5]
            |      |
            |      |
            |      |
           [4]----[3]
    THE INPUT>>>
    0 1
    1 2
    2 5
    1 4
    2 3
    4 3
    */
}





