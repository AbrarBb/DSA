#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;
vector<int> graph[MAX];
bool visited[MAX];


void DFS(int node) 
{
    cout << "Visited " << node << " in DFS" << endl;
    visited[node] = true;

    for (int neighbor : graph[node]) 
    {
        if (!visited[neighbor]) 
        {
            DFS(neighbor);
        }
    }
}
void BFS(int start) 
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        cout << "Visited " << node << " in BFS" << endl;

        for (int neighbor : graph[node]) 
        {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() 
{
    int edges, x, y;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter each edge (format: start end):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int startNode;
    cout << "Enter starting node: ";
    cin >> startNode;

    cout << "Choose traversal (1 for DFS, 2 for BFS): ";
    int choice;
    cin >> choice;

    fill(begin(visited), end(visited), false);

    if (choice == 1) 
    {
        DFS(startNode);
    } 
    else if (choice == 2) 
    {
        BFS(startNode);
    } 
    else 
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
