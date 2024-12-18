#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(int nodeCount, vector<vector<int>> edges, int start) 
{
    vector<int> distances(nodeCount, INT_MAX); 
    distances[start] = 0;

    for (int a = 0; a < nodeCount - 1; a++) 
    { 
        for (auto edge : edges) 
        {
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];

            if (distances[source] != INT_MAX && distances[source] + weight < distances[destination]) 
            {
                distances[destination] = distances[source] + weight;
            }
        }
    }

    cout << "Shortest distances from node " << start << ":" << endl;
    for (int a = 0; a < nodeCount; a++) 
    {
        cout << "To node " << a << ": " << (distances[a] == INT_MAX ? -1 : distances[a]) << endl;
    }
}

int main() 
{
    
    vector<vector<int>> edges = 
    {
        {0, 1, 1},  
        {0, 2, 4},  
        {1, 2, 2},  
        {1, 3, 6},  
        {2, 3, 3}   
    };


    int nodeCount = 4; 
    int startNode = 0; 
    dijkstra(nodeCount, edges, startNode);

    return 0;
}
