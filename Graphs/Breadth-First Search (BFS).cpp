#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start) 
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) 
        {
            if (!visited[neighbor]) 
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() 
{
    int nodes, edges;
    cin >> nodes >> edges;

    graph.resize(nodes + 1);
    visited.resize(nodes + 1, false);

    for (int a = 0; a < edges; a++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cin >> start;

    bfs(start);
    cout << endl;

    return 0;
}
