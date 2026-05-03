#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *l; // Pointer to an array of adjacency lists

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    ~Graph() { // Destructor to free allocated memory
        delete[] l;
    }

    // Function to add an edge from source to destination
    void addEdge(int src, int dest) {
        l[src].push_back(dest); // Add dest to src's list
        l[dest].push_back(src); // Add src to dest's list (for undirected graph)
    }

    // Function to display the graph
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (auto& vertex : l[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    // BFS Traversal
    void bfs(int src) {
        queue<int> Q;
        vector<bool> vis(V, false);
        
        Q.push(src);
        vis[src] = true;

        while(Q.size() > 0) {
            int u = Q.front();
            Q.pop();

            cout << u << " ";

            for(int v : l[u]) {
                if(!vis[v]) { // Corrected this line
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph(); // Print the graph

    g.bfs(0); // Call bfs with the source vertex
    return 0;
}