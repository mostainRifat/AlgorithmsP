#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int visited[N];
vector<int> adjList[N];

bool detectCycle(int src)
{
    visited[src] = 1;
    for (int i : adjList[src])
    {
        if (visited[i] == 0)
        {
            bool Cycle = detectCycle(i);
            if(Cycle)
            {
                return true;
            }
        }

        else if (visited[i] == 1)
        {
            return true;
        }
    }
    visited[src]=2;
    return false;
}

int main()
{
    int vertex;
    int edge;
    cin >> vertex >> edge;
    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    bool cycle_exists = false;

    for (int i = 1; i <= vertex; i++)
    {
        if (visited[i] == 0)
        {
            bool gotCycle = detectCycle(i);
            if(gotCycle)
            {
                cycle_exists= true;
                break;
            }

        }
    }

    if (cycle_exists)
        cout << "Cycle Exists"<<endl;
    else
        cout << "No Cycle"<<endl;
    return 0;
}
