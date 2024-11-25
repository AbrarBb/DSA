#include <iostream>
#include <vector>
using namespace std;

// Function to display adjacency list
void printAdjacencyList(vector<vector<int>> &adj) 
{
    for (int a = 0; a < adj.size(); a++) 
    {
        cout << "Vertex " << a + 1 << " -> ";
        for (int b : adj[a]) 
        {
            cout << b + 1 << " "; // Display neighbors
        }
        cout << endl;
    }
}

int main() {
    int vertices = 3;

    // Create an adjacency list
    vector<vector<int>> adj(vertices);

    // Add edges
    adj[0].push_back(1); // Edge from 1 to 2
    adj[0].push_back(2); // Edge from 1 to 3
    adj[1].push_back(0); // Edge from 2 to 1
    adj[2].push_back(1); // Edge from 3 to 2

    printAdjacencyList(adj);
    return 0;
}
