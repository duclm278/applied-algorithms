// TODO
#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    int V;           // No. of vertices
    list<int> *adj;  // Pointer to array of adjacency lists (double
                     // linked list)
    bool *visited;
    Graph(int V);                // Constructor
    void addEdge(int v, int w);  // Add edge to graph
    void BFS(int s);             // Print BFS traversal from given source s
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);  // Add v to u's list
    // adj[v].push_back(u);
}

void Graph::BFS(int s) {
    visited[s] = 1;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        cout << u << " ";
        for (list<int>::iterator i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = *i;
            if (visited[v] == 0) {
                visited[v] = 1;
                Q.push(v);
                pred[v] = u;
            }
        }
    }
}

int main() {
    // Create directed graph with 5 vertices, 6 edges
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 0);
    g.addEdge(3, 0);

    // Init
    g.visited = new bool(g.V);
    for (int i = 0; i < g.V; i++) {
        g.visited[i] = false;
        pred[i] = -1;
    }

    cout << "BFS(1): ";
    g.BFS(1);
    return 0;
}
