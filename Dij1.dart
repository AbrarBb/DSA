void dijkstra(List<String> nodes, List<List<dynamic>> edges, String start) {
  int n = nodes.length;
  List<int> distances = List.filled(n, 99999); 
  List<bool> visited = List.filled(n, false); 
  
  int startIndex = nodes.indexOf(start);
  distances[startIndex] = 0; 

  for (int count = 0; count < n; count++) 
  {
    int minDistance = 99999, u = -1;
    for (int a = 0; a < n; a++) 
    {
      if (!visited[a] && distances[a] < minDistance) 
      {
        minDistance = distances[a];
        u = a;
      }
    }

    if (u == -1) break; 
    visited[u] = true;

    for (var edge in edges) 
    {
      int source = nodes.indexOf(edge[0]);
      int destination = nodes.indexOf(edge[1]);
      int weight = edge[2];

      if (source == u && !visited[destination] &&
          distances[source] + weight < distances[destination]) 
      {
        distances[destination] = distances[source] + weight;
      }

      if (destination == u && !visited[source] &&
          distances[destination] + weight < distances[source]) 
      {
        distances[source] = distances[destination] + weight;
      }
    }
  }


  print('Shortest distances from $start:');
  for (int a = 0; a < n; a++) 
  {
    print('To ${nodes[a]}: ${distances[a]}');
  }
}

void main() 
{
  var nodes = ['A', 'B', 'C', 'D', 'E', 'F'];
  
  var edges = [
    ['A', 'B', 14],
    ['A', 'C', 9],
    ['A', 'F', 7],
    ['B', 'C', 2],
    ['B', 'D', 8],
    ['C', 'F', 10],
    ['C', 'E', 11],
    ['D', 'E', 6],
    ['E', 'F', 15],
  ];
  dijkstra(nodes, edges, 'A');
}
