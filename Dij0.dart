class Edge {
  final String source;
  final String destination;
  final int weight;

  Edge(this.source, this.destination, this.weight);
}

void dijkstra(List<String> nodes, List<Edge> edges, String start) {
  int n = nodes.length;
  var distances = List.filled(n, 99999);
  var visited = List.filled(n, false);

  distances[nodes.indexOf(start)] = 0;

  for (var _ in List.generate(n, (_) => 0)) {
    int minDistance = 99999, u = -1;

    for (var i = 0; i < n; i++) {
      if (!visited[i] && distances[i] < minDistance) {
        minDistance = distances[i];
        u = i;
      }
    }

    if (u == -1) break;
    visited[u] = true;

    for (var edge in edges) {
      if (edge.source == nodes[u]) {
        int v = nodes.indexOf(edge.destination);
        if (!visited[v] && distances[u] + edge.weight < distances[v]) {
          distances[v] = distances[u] + edge.weight;
        }
      }
    }
  }

  print('Shortest distances from $start:');
  for (var i = 0; i < n; i++) {
    print('To ${nodes[i]}: ${distances[i]}');
  }
}

void main() {
  var nodes = ['A', 'B', 'C', 'D', 'E', 'F'];
  var edges = [
    Edge('A', 'B', 14),
    Edge('A', 'C', 9),
    Edge('A', 'F', 7),
    Edge('B', 'C', 2),
    Edge('B', 'D', 8),
    Edge('C', 'F', 10),
    Edge('D', 'E', 6),
    Edge('E', 'F', 15),
  ];

  dijkstra(nodes, edges, 'A'); // Start from node A
}
