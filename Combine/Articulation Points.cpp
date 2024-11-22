#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &ap, int &time) {
    visited[u] = true;
    disc[u] = low[u] = ++time; // Initialize discovery and low time
    int children = 0;

    for (int v : graph[u]) 
    {
        if (!visited[v]) 
        {
            children++;
            parent[v] = u;
            dfs(v, graph, visited, disc, low, parent, ap, time);

            low[u] = min(low[u], low[v]); // Update low value of u

            if (parent[u] == -1 && children > 1) ap[u] = true; // Root with 2+ children
            if (parent[u] != -1 && low[v] >= disc[u]) ap[u] = true; // Child can't reach ancestors
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findArticulationPoints(vector<vector<int>> &graph, int n) {
    vector<bool> visited(n, false), ap(n, false);
    vector<int> disc(n), low(n), parent(n, -1);
    int time = 0;

    for (int a = 0; a < n; a++) 
    {
        if (!visited[a]) dfs(a, graph, visited, disc, low, parent, ap, time);
    }

    cout << "Articulation Points: ";
    for (int a = 0; a < n; a++) 
    {
        if (ap[a]) cout << a + 1 << " ";
    }
    cout << endl;
}

int main() 
{
    int n = 5;
    vector<vector<int>> graph(n);

    // Example graph
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1};
    graph[3] = {1, 4};
    graph[4] = {3};

    findArticulationPoints(graph, n);
    return 0;
}
