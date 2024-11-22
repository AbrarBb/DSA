#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS function
void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) 
{
    cout << "Visited " << node + 1 << endl;
    visited[node] = true;

    for (int a : graph[node]) 
    {
        if (!visited[a]) 
        {
            dfs(a, graph, visited);
        }
    }
}

int main() 
{
    int vertices = 4;
    vector<vector<int>> graph(vertices);

    // Add edges
    graph[0] = {1, 2};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {3};

    vector<bool> visited(vertices, false);

    dfs(0, graph, visited); // Start DFS from vertex 1
    return 0;
}
