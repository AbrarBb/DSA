void main() 
{
  // Graph representation as an adjacency list
  List<List<int>> graph = [
    [1, 2],    // Node 0 is connected to 1 and 2
    [0, 2, 3], // Node 1 is connected to 0, 2, and 3
    [0, 1, 3], // Node 2 is connected to 0, 1, and 3
    [1, 2, 4], // Node 3 is connected to 1, 2, and 4
    [3]        // Node 4 is connected to 3
  ];

  // Find and print articulation points
  findArticulationPoints(graph);
}

void findArticulationPoints(List<List<int>> graph) 
{
  int n = graph.length;  // Number of nodes
  List<bool> visited = List.filled(n, false);   // To track visited nodes
  List<int> discovery = List.filled(n, -1);     // To track discovery time of nodes
  List<int> low = List.filled(n, -1);           // To track low time
  List<bool> articulation = List.filled(n, false); // To mark articulation points
  int time = 0;  // Timer for discovery times

  // Visit each node
  for (int i = 0; i < n; i++) 
  {
    if (!visited[i]) 
    {
      dfs(i, -1, graph, visited, discovery, low, articulation, time);
    }
  }

  // Print articulation points
  for (int i = 0; i < n; i++) 
  {
    if (articulation[i]) 
    {
      print("Articulation Point: $i");
    }
  }
}

void dfs(int node, int parent, List<List<int>> graph, List<bool> visited,
    List<int> discovery, List<int> low, List<bool> articulation, int time) 
{
  visited[node] = true;
  discovery[node] = low[node] = time++; // Set discovery time for the node
  int children = 0; // Count children of the node

  // Check all neighbors (connected nodes)
  for (int neighbor in graph[node]) 
  {
    if (!visited[neighbor]) 
    {
      children++;  // Increase child count
      dfs(neighbor, node, graph, visited, discovery, low, articulation, time);
      low[node] = low[node] < low[neighbor] ? low[node] : low[neighbor];

      // If node is not the root and cannot reach any ancestor, it's an articulation point
      if (parent != -1 && low[neighbor] >= discovery[node]) 
      {
        articulation[node] = true;
      }
    } else if (neighbor != parent) {
      low[node] = low[node] < discovery[neighbor] ? low[node] : discovery[neighbor];
    }
  }

  // If node is the root and has more than one child, it's an articulation point
  if (parent == -1 && children > 1) {
    articulation[node] = true;
  }
}
