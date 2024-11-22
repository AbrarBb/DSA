#include <iostream>
using namespace std;

// Function to print adjacency matrix
void printAdjacencyMatrix(int graph[][3], int n) 
{
    for (int a = 0; a < n; a++) 
    {
        for (int b = 0; b < n; b++) 
        {
            cout << graph[a][b] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    // Graph as adjacency matrix
    int graph[3][3] = 
    {
        {0, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };

    printAdjacencyMatrix(graph, 3); // Number of vertices is 3
    return 0;
}
