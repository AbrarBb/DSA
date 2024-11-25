#include <iostream>
using namespace std;

// Function to calculate in-degree and out-degree
void calculateDegrees(int graph[][3], int n) 
{
    int in_deg[3] = {0};  // Stores in-degrees
    int out_deg[3] = {0}; // Stores out-degrees

    for (int a = 0; a < n; a++) 
    {
        for (int b = 0; b < n; b++) 
        {
            if (graph[a][b] == 1) 
            {
                out_deg[a]++;  // Count outgoing edges
                in_deg[b]++;   // Count incoming edges
            }
        }
    }

    // Display results
    for (int a = 0; a < n; a++) 
    {
        cout << "Vertex " << a + 1 << " -> In-Degree: " << in_deg[a]
             << ", Out-Degree: " << out_deg[a] << endl;
    }
}

int main() 
{
    // Graph as an adjacency matrix
    int graph[3][3] = {
        {0, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };

    calculateDegrees(graph, 3); // Number of vertices is 3
    return 0;
}
