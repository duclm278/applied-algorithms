#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    int V;           // Number of vertices
    list<int> *adj;  // Pointer to array of adjacency lists
    bool *visited;
    int *pred;
    int *color;
    Graph(int V);  // Constructor
    void addEdge(int v, int w);
    void topoSortDFS();
    void topoSortBFS();
    void topoDFS(int s, stack<int> &Stack);
    bool isBipartie(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) { adj[u].push_back(v); }

bool Graph::isBipartie(int s) {
    // All vertices are initially uncolored
    for (int v = 0; v < V; v++) color[v] = -1;

    // First vertex is colored 1
    color[s] = 1;

    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            int v = *itr;
            // Detect self-loop
            if (u == v) return false;
            // If v is uncolored, color it with opposite color of u
            else if (color[v] == -1) {
                color[v] = 1 - color[u];
                Q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }

    return true;
}

void Graph::topoSortDFS() {
    for (int s = 0; s < V; s++) visited[s] = false;
    stack<int> Stack;
    for (int s = 0; s < V; s++)
        if (visited[s] == false) topoDFS(s, Stack);

    // Print content of stack
    cout << "Topological order using DFS: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << "\n";
}

void Graph::topoDFS(int s, stack<int> &Stack) {
    visited[s] = true;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        cout << u << " ";
        list<int>::iterator i;
        for (i = adj[s].begin(); i != adj[s].end(); i++) {
            int v = *i;
            if (visited[v] == false) {
                visited[v] = true;
                topoDFS(v, Stack);
                pred[v] = u;
            }
        }
    }
    Stack.push(s);
}

void Graph::topoSortBFS() {
    vector<int> inDegrees(V, 0);
    for (int v = 0; v < V; v++) {
        list<int>::iterator itr;
        for (itr = adj[v].begin(); itr != adj[v].end(); itr++) {
            inDegrees[*itr]++;
        }
    }

    queue<int> Q;
    for (int v = 0; v < V; v++) {
        if (inDegrees[v] == 0) Q.push(v);
    }

    int num = 0;
    vector<int> topoOrder;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        num++;
        topoOrder.push_back(v);
        list<int>::iterator itr;
        for (itr = adj[v].begin(); itr != adj[v].end(); itr++) {
            --inDegrees[*itr];
            if (inDegrees[*itr] == 0) Q.push(*itr);
        }
    }

    // Print content of queue
    cout << "Topological order using BFS: ";
    for (int v : topoOrder) cout << v << " ";
    cout << "\n";
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 0);
    g.addEdge(0, 3);

    // Init
    g.visited = new bool[g.V];
    g.pred = new int[g.V];
    g.color = new int[g.V];
    for (int i = 0; i < g.V; i++) {
        g.visited[i] = false;
        g.pred[i] = -1;
    }

    // If bipartie, print vertices having color
    // Print vertices having color
    if (g.isBipartie(0)) {
        cout << "Is bipartie\n";
        for (int i = 0; i < g.V; i++) {
            if (g.color[i] != -1)
                cout << "Vertex " << i << " has color " << g.color[i] << "\n";
        }
    } else {
        cout << "Not bipartie\n";
    }

    return 0;
}
