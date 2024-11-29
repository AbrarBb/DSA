#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;   
vector<bool> visited;        

void dfs(int node) 
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) 
    {
        if (!visited[neighbor]) 
        {
            dfs(neighbor);
        }
    }
}

int main() 
{
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    graph.resize(nodes + 1);
    visited.resize(nodes + 1, false);

    cout << "Enter each edge (two nodes per edge):" << endl;
    for (int a = 0; a < edges; a++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  
    }
    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    cout << "DFS traversal from node " << start << ": ";
    dfs(start);
    cout << endl;

    return 0;
}
