#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &stk) 
{
    visited[u] = true;
    for (int v : graph[u]) 
    {
        if (!visited[v]) dfs(v, graph, visited, stk);
    }
    stk.push(u);
}

void reverseGraph(vector<vector<int>> &graph, vector<vector<int>> &transposed, int n) 
{
    for (int a = 0; a < n; a++) 
    {
        for (int b : graph[a]) 
        {
            transposed[b].push_back(a);
        }
    }
}

void printSCC(int u, vector<vector<int>> &graph, vector<bool> &visited) 
{
    visited[u] = true;
    cout << u + 1 << " ";
    for (int v : graph[u]) 
    {
        if (!visited[v]) printSCC(v, graph, visited);
    }
}

void findSCCs(vector<vector<int>> &graph, int n) 
{
    stack<int> stk;
    vector<bool> visited(n, false);

    for (int a = 0; a < n; a++) 
    {
        if (!visited[a]) dfs(a, graph, visited, stk);
    }

    vector<vector<int>> transposed(n);
    reverseGraph(graph, transposed, n);
    fill(visited.begin(), visited.end(), false);

    cout << "Strongly Connected Components:\n";
    while (!stk.empty()) 
    {
        int u = stk.top();
        stk.pop();
        if (!visited[u]) 
        {
            printSCC(u, transposed, visited);
            cout << endl;
        }
    }
}

int main() 
{
    int n = 5;
    vector<vector<int>> graph(n);

    // Example graph
    graph[0] = {1};
    graph[1] = {2};
    graph[2] = {0, 3};
    graph[3] = {4};
    graph[4] = {};

    findSCCs(graph, n);
    return 0;
}
