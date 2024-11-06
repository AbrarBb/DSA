#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;    // Adjacency list for the graph
vector<bool> visited;         // Visited array to keep track of visited nodes

void bfs(int startNode) {
    queue<int> q;             // Queue for BFS
    q.push(startNode);        // Start BFS from the startNode
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();  // Get the node at the front of the queue
        q.pop();               // Remove it from the queue
        cout << node << " ";   // Print the node as part of BFS traversal

        // Go through all neighbors of the current node
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {   // If the neighbor has not been visited
                q.push(neighbor);       // Add it to the queue
                visited[neighbor] = true; // Mark it as visited
            }
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    // Resize the graph and visited array based on the number of nodes
    graph.resize(nodes + 1);
    visited.resize(nodes + 1, false);

    // Taking input for each edge
    cout << "Enter each edge (two nodes per edge):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Add edge u -> v
        graph[v].push_back(u); // Add edge v -> u (for undirected graph)
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    cout << "BFS traversal from node " << start << ": ";
    bfs(start);  // Start BFS from the specified starting node
    cout << endl;

    return 0;
}
