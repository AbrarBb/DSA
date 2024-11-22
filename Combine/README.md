Graph Theory and Sorting Algorithms

Table of Contents
 -Graph Theory

    Degrees of a Graph
    Adjacency List
    Adjacency Matrix
   Articulation Points
   Strongly Connected Components (SCCs)

  -Graph Traversal Algorithms

    Depth First Search (DFS)
    Breadth First Search (BFS)
  
  -Sorting Algorithms

    Topological Sort
    Binary Sort
    Quick Sort
   Merge Sort

1. Graph Theory
 1.1 Degrees of a Graph
Explanation:
The degree of a vertex is the number of edges connected to it. It helps us understand how connected a vertex is to others in the graph.

Code Example:
The code below calculates the degree for each vertex in a graph using an adjacency list representation.

// Example for graph with adjacency list
vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1}};

1.2 Adjacency List
Explanation:
An adjacency list is a collection of lists used to represent a graph. Each vertex in the graph has a list that contains all of its neighbors.

Code Example:

vector<vector<int>> graph = {
    {1, 2}, // Vertex 1 is connected to vertices 2
    {0, 2}, // Vertex 2 is connected to vertices 1
    {0, 1}  // Vertex 3 is connected to vertices 1
};

1.3 Adjacency Matrix
Explanation:
An adjacency matrix is a 2D array where the element at row i and column j is 1 if there is an edge between vertex i and vertex j, otherwise 0.

Code Example:

int graph[3][3] = {
    {0, 1, 1}, // Vertex 1 is connected to vertex 2 and 3
    {1, 0, 1}, // Vertex 2 is connected to vertex 1 and 3
    {1, 1, 0}  // Vertex 3 is connected to vertex 1 and 2
};

1.4 Articulation Points
Explanation:
Articulation points are vertices that, if removed, make the graph disconnected. We use Depth First Search (DFS) to find them.

Code Example:

void findArticulationPoints(vector<vector<int>> &graph) {
    // DFS logic to find articulation points
}

1.5 Strongly Connected Components (SCCs)
Explanation:
SCCs are subgraphs where every vertex is reachable from every other vertex in the same subgraph. Kosaraju’s algorithm is used to find SCCs.

Code Example:

void findSCCs(vector<vector<int>> &graph) {
    // DFS and reverse DFS logic for SCC
}

2. Graph Traversal Algorithms
  2.1 Depth First Search (DFS)
Explanation:
DFS explores a graph starting from the root and goes as deep as possible before backtracking.

Code Example:

void dfs(int vertex, vector<vector<int>> &graph) {
    // DFS implementation
}
2.2 Breadth First Search (BFS)
Explanation:
BFS explores the graph level by level, visiting all neighbors of a vertex before moving to the next level.

Code Example:

void bfs(int start, vector<vector<int>> &graph) {
    // BFS implementation
}

3. Sorting Algorithms
  3.1 Topological Sort
Explanation:
Topological Sort orders vertices in a directed graph such that for every directed edge u -> v, vertex u comes before v.

Code Example:

void topologicalSort(vector<vector<int>> &graph) {
    // Topological Sort implementation using DFS
}

3.2 Binary Sort (Binary Insertion Sort)
Explanation:
Binary Sort is a variant of the insertion sort algorithm where binary search is used to find the correct position for each element.

Code Example:


void binarySort(int arr[], int n) {
    // Binary Insertion Sort implementation
}

3.3 Quick Sort
Explanation:
Quick Sort is a divide-and-conquer algorithm. It picks a "pivot" element, partitions the array around the pivot, and recursively sorts the subarrays.

Code Example:


void quickSort(int arr[], int low, int high) {
    // Quick Sort implementation
}

3.4 Merge Sort
Explanation:
Merge Sort is another divide-and-conquer algorithm that splits the array into two halves, sorts them, and merges them back together.

Code Example:

void mergeSort(int arr[], int low, int high) {
    // Merge Sort implementation
}

