#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoDFS(int u, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &stk) 
{
    visited[u] = true;
    for (int v : graph[u]) 
    {
        if (!visited[v]) topoDFS(v, graph, visited, stk);
    }
    stk.push(u);
}

void topologicalSort(vector<vector<int>> &graph, int n) 
{
    stack<int> stk;
    vector<bool> visited(n, false);

    for (int a = 0; a < n; a++) 
    {
        if (!visited[a]) topoDFS(a, graph, visited, stk);
    }

    cout << "Topological Sort: ";
    while (!stk.empty()) 
    {
        cout << stk.top() + 1 << " ";
        stk.pop();
    }
    cout << endl;
}

int main() 
{
    int n = 6;
    vector<vector<int>> graph(n);

    // Directed Acyclic Graph (DAG)
    graph[5] = {0, 2};
    graph[4] = {0, 1};
    graph[2] = {3};
    graph[3] = {1};

    topologicalSort(graph, n);
    return 0;
}
