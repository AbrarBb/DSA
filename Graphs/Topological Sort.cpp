#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
stack<int> result;

void dfs(int node) 
{
    visited[node] = true;
    for (int neighbor : graph[node]) 
   {
        if (!visited[neighbor]) 
        {
            dfs(neighbor);
        }
    }
    result.push(node); // Push the node after all its neighbors are processed
}

int main() 
{
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    graph.resize(nodes);
    visited.resize(nodes, false);

    cout << "Enter each edge (two nodes per edge):" << endl;
    for (int a = 0; a < edges; a++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Directed graph
    }

    cout << "Topological Sort: ";
    for (int a = 0; a < nodes; a++) 
    {
        if (!visited[a]) 
        {
            dfs(a);
        }
    }

    while (!result.empty()) 
    {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;

    return 0;
}
