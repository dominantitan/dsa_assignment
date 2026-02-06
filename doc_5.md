# Program 5 Documentation

## Data Structures
- **adj[MAX][MAX]**: 2D adjacency matrix to represent undirected graph
- **visited[MAX]**: Array to track visited vertices during traversal
- **queue[MAX]**: Simple array-based queue for BFS implementation

## Functions Implemented
- **create_graph()**: Takes input for vertices and edges, builds adjacency matrix
- **display_matrix()**: Shows the adjacency matrix representation
- **dfs(int start)**: Recursive depth-first search traversal
- **bfs(int start)**: Breadth-first search using queue

## Main Method Organization
1. Creates graph by taking user input
2. Displays adjacency matrix
3. Shows menu for DFS/BFS operations
4. Takes starting vertex and performs selected traversal
5. Repeats until user exits

## Sample Output
```
enter no of vertices: 4
enter no of edges: 4
enter edge (u v): 0 1
enter edge (u v): 0 2
enter edge (u v): 1 3
enter edge (u v): 2 3

adjacency matrix:
0 1 1 0 
1 0 0 1 
1 0 0 1 
0 1 1 0 

1.DFS 2.BFS 3.exit
choice: 1
enter starting vertex for DFS: 0
DFS traversal: 0 1 3 2 

1.DFS 2.BFS 3.exit
choice: 2
enter starting vertex for BFS: 0
BFS traversal: 0 1 2 3 
```
