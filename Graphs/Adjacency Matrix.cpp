#include <iostream>
using namespace std;

int main() 
{
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    int graph[nodes][nodes] = {};

    cout << "Enter each edge (from node to node):" << endl;
    for (int a = 0; a < edges; a++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1; 
    }

    cout << "Adjacency Matrix:" << endl;
    for (int a = 0; a < nodes; a++) 
    {
        for (int b = 0; b < nodes; b++) 
        {
            cout << graph[a][b] << " ";
        }
        cout << endl;
    }

    return 0;
}
