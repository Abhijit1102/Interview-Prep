# Graph Data Structure Example

This project demonstrates the implementation of a simple undirected graph in C++ using an adjacency list.

## Overview
The `Graph` class provides methods for adding edges, and displaying the graph. It is designed to manage the graph's memory efficiently by freeing allocated resources in the destructor.

## Features
- **Add Edge:** Connect two vertices.
- **Display Graph:** Print the adjacency list representation of the graph.

## Defining a Graph
A graph is defined by a set of vertices (or nodes) and a set of edges that connect pairs of vertices. In this example, the `Graph` class handles an undirected graph, meaning that the edges have no direction. The example creates a graph with 5 vertices and establishes connections (edges) between them. Here’s how you can define a graph and add edges:

## BFS - Breadth First Search

Breadth First Search (BFS) is a graph traversal algorithm that explores all the vertices of a graph in breadthward motion, meaning it explores all neighbors at the present depth prior to moving on to vertices at the next depth level.

### How It Works:
1. **Initialization:** It uses a queue to keep track of the vertices to be explored and an array to check whether a vertex has already been visited.
2. **Traversal:** Starting from a source vertex, it visits all its adjacent vertices, marks them as visited, and adds them to the queue.
3. **Continue:** This process continues until all vertices connected to the source vertex have been visited.

### Example Usage:
To perform BFS on the graph, you can call the `bfs` method after creating your `Graph` object. For example:
```cpp
int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.bfs(0); // Call bfs with the source vertex
    return 0;
}
```
This will start the BFS traversal from vertex `0` and print the order of vertices visited.