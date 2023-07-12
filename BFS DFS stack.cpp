#include <bits/stdc++.h>
using namespace std;
const int vertex =6;
vector<int> adjenlist[vertex];
bool visited[vertex];
void BFS(int source_node);
void DFS(int source_node)
{
    stack<int> st;
    st.push(source_node);
    while (!st.empty())
    {
        if (visited[st.top()] == false)
        {
            cout << st.top() << " ";
            visited[st.top()] = true;
        }
        int index = 0;
        for (auto j : adjenlist[st.top()])
        {
            int l = adjenlist[st.top()].size();
            if (visited[j] == false)
            {
                st.push(j);
                index = 0;
                break;
            }
            index++;
            if (index == l)
            {
                st.pop();
                index = 0;
                break;
            }
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
//    cout << "dfs is"<< "\n";
//    DFS(sourc_node);
    cout <<"\n"<< "dfs is"<< "\n";
    BFS(sourc_node);

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
void BFS(int source_node)
{
    queue<int>q;
    q.push(source_node);
    while(!q.empty())
    {
        auto a=q.front();
        q.pop();
        visited[a] = true;
        cout<<a<<" ";
        for (auto j : adjenlist[a])
            if (visited[j] == false)
                q.push(j);
    }
}
