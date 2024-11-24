void main() 
{
  // Number of nodes
  int nodes = 5;

  // Graph adjacency list
  List<List<int>> graph = [
    [1],    // Node 0 -> 1
    [2],    // Node 1 -> 2
    [0, 3], // Node 2 -> 0, 3
    [4],    // Node 3 -> 4
    []      // Node 4 -> None
  ];

  findSCCs(nodes, graph);
}

void findSCCs(int nodes, List<List<int>> graph) 
{
  // Step 1: Create a reversed graph
  List<List<int>> reversedGraph = List.generate(nodes, (_) => []);
  for (int u = 0; u < nodes; u++) 
  {
    for (int v in graph[u]) {
      reversedGraph[v].add(u); // Reverse the edges
    }
  }

  // Step 2: Find finish order using DFS
  List<bool> visited = List.filled(nodes, false);
  List<int> order = [];
  for (int i = 0; i < nodes; i++) 
  {
    if (!visited[i]) 
    {
      _dfsOrder(i, graph, visited, order);
    }
  }

  // Step 3: Process nodes in reversed order on reversed graph
  visited = List.filled(nodes, false);
  print("Strongly Connected Components:");
  for (int i = order.length - 1; i >= 0; i--) 
  {
    int node = order[i];
    if (!visited[node]) 
    {
      _dfsPrint(node, reversedGraph, visited);
      print("----");
    }
  }
}

void _dfsOrder(int node, List<List<int>> graph, List<bool> visited, List<int> order) 
{
  visited[node] = true;
  for (int neighbor in graph[node]) 
  {
    if (!visited[neighbor]) 
    {
      _dfsOrder(neighbor, graph, visited, order);
    }
  }
  order.add(node); // Add node to the finish order
}

void _dfsPrint(int node, List<List<int>> graph, List<bool> visited) 
{
  visited[node] = true;
  print(node); // Print node as part of the SCC
  for (int neighbor in graph[node]) 
  {
    if (!visited[neighbor]) 
    {
      _dfsPrint(neighbor, graph, visited);
    }
  }
}
