#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 1000;
vector<int> graph[MAX], transpose[MAX];
bool visited[MAX];
stack<int> nodeStack;

void dfs1(int node) 
{
    visited[node] = true;
    for (int neighbor : graph[node]) 
    {
        if (!visited[neighbor]) 
        {
            dfs1(neighbor);
        }
    }
    nodeStack.push(node);
}

void dfs2(int node) 
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : transpose[node]) 
    {
        if (!visited[neighbor]) 
        {
            dfs2(neighbor);
        }
    }
}

/*void addEdge(int u, int v) 
{
    graph[u].push_back(v);
}*/

void findSCCs(int nodes) {
    for (int a = 1; a <= nodes; a++) 
    {
        if (!visited[a]) {
            dfs1(a);
        }
    }
    for (int a = 1; a <= nodes; a++) 
    {
        for (int neighbor : graph[a]) 
        {
            transpose[neighbor].push_back(a);
        }
    }
    fill(begin(visited), end(visited), false);
    cout << "Strongly Connected Components are:\n";
    while (!nodeStack.empty()) 
    {
        int node = nodeStack.top();
        nodeStack.pop();
        if (!visited[node]) 
        {
            dfs2(node);
            cout << endl;
        }
    }
}

int main() 
{
    int nodes, edges, u, v;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    cout << "Enter each directed edge (format: from to):" << endl;
    for (int a = 0; a < edges; a++) 
    {
        cin >> u >> v;
        graph[u].push_back(v);
        //addEdge(u, v);
    }
    findSCCs(nodes);
    return 0;
}
