# Program 7 Documentation

## Data Structures
- **graph[MAX][MAX]**: Adjacency matrix to store weighted edges
- **dist[MAX]**: Array to store shortest distances from source
- **visited[MAX]**: Array to track processed vertices
- **n**: Number of vertices in graph

## Functions Implemented
- **create_graph()**: Takes input for weighted graph using adjacency matrix
- **find_min_dist()**: Finds unvisited vertex with minimum distance
- **dijkstra(int src)**: Main algorithm to find shortest paths
- **print_solution(int src)**: Displays shortest distances from source

## Main Method Organization
1. Creates weighted graph by taking edges and weights
2. Takes source vertex as input
3. Runs Dijkstra's algorithm from source
4. Prints shortest distances to all vertices

## Sample Output
```
enter no of vertices: 5
enter no of edges: 7
enter edge (u v weight): 0 1 2
enter edge (u v weight): 0 3 6
enter edge (u v weight): 1 2 3
enter edge (u v weight): 1 3 8
enter edge (u v weight): 1 4 5
enter edge (u v weight): 2 4 7
enter edge (u v weight): 3 4 9

enter source vertex: 0

shortest distances from vertex 0:
vertex 0: 0
vertex 1: 2
vertex 2: 5
vertex 3: 6
vertex 4: 7
```
