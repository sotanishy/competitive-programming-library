# Dinic's Algorithm

Dinic's algorithm is an algorithm for findng the maximum flow. It continuously calculates the shortest distance from the source using BFS, finds an augmenting path in the residual graph using DFS, and sends flow along the path.

# Methods

- `Dinic(int n)`
    - Initializes the graph with $n$ vertices.
    - Time complexity: $O(n)$
- `void add_edge(int u, int v, T cap)`
    - Adds an edge $(u, v)$ with a capacity $cap$.
    - Time complexity: $O(1)$
- `T max_flow(int s, int t)`
    - Calculates the maximum flow from the source $s$ to the sink $t$.
    - Time complexity: $O(V^2E)$