#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;
const long long INF = 1e18;

vector<pair<int, int>> adjList[N];

int visited[N], parent[N];
int nodes, edges;
long long d[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<long long, int> head = pq.top();
        pq.pop();
        int selectedNode = head.second;

        if (visited[selectedNode])
            continue;

        visited[selectedNode] = 1;

        for (auto adjEntry : adjList[selectedNode])
        {
            int adj_node = adjEntry.first;
            int edge_cst = adjEntry.second;

            if (d[selectedNode] + edge_cst < d[adj_node])
            {
                d[adj_node] = d[selectedNode] + edge_cst;
                parent[adj_node] = selectedNode;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    if (visited[nodes] == 0)
    {
        cout << "-1" << endl;
        return 0;
    }

    int currentNode = nodes;
    vector<int> path;

    while (true)
    {
        path.push_back(currentNode);
        if (currentNode == src)
            break;

        currentNode = parent[currentNode];
    }
    reverse(path.begin(), path.end());

    for (int node : path)
    {
        cout << node << " ";
    }
    cout << endl;
}
