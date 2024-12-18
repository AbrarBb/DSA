#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int nodeCount, vector<vector<pair<int, int>>> adj, int start) 
{
    vector<int> distances(nodeCount, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) 
    {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (currDist > distances[currNode]) continue;

        for (auto neighbor : adj[currNode]) 
        {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (distances[currNode] + weight < distances[nextNode]) 
            {
                distances[nextNode] = distances[currNode] + weight;
                pq.push({distances[nextNode], nextNode});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":" << endl;
    for (int a = 0; a < nodeCount; a++) 
    {
        cout << "To node " << a << ": " << (distances[a] == INT_MAX ? -1 : distances[a]) << endl;
    }
}

int main() {
    int nodeCount = 6; 
    vector<vector<pair<int, int>>> adj(nodeCount);

    adj[0] = {{1, 14}, {2, 9}, {5, 7}}; // A -> B, C, F
    adj[1] = {{0, 14}, {2, 2}, {3, 8}}; // B -> A, C, D
    adj[2] = {{0, 9}, {1, 2}, {5, 10}, {4, 11}}; // C -> A, B, F, E
    adj[3] = {{1, 8}, {4, 6}}; // D -> B, E
    adj[4] = {{3, 6}, {2, 11}, {5, 15}}; // E -> D, C, F
    adj[5] = {{0, 7}, {2, 10}, {4, 15}}; // F -> A, C, E

    int startNode = 0; 
    dijkstra(nodeCount, adj, startNode);

    return 0;
}
