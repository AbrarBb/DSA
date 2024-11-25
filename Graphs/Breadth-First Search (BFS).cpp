#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited) 
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        cout << "Visited " << node + 1 << endl;

        for (int a : graph[node]) 
        {
            if (!visited[a]) 
            {
                q.push(a);
                visited[a] = true;
            }
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

    bfs(0, graph, visited); // Start BFS from vertex 1
    return 0;
}
