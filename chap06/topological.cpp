#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    int V;           // Number of vertices
    list<int> *adj;  // Pointer to array of adjacency lists
    bool *visited;
    int *pred;
    Graph(int V);  // Constructor
    void addEdge(int v, int w);
    void topoSortDFS();
    void topoSortBFS();
    void topoDFS(int s, stack<int> &Stack);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) { adj[u].push_back(v); }

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

int main() {
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 0);
    g.addEdge(0, 2);

    // Init
    g.visited = new bool[g.V];
    g.pred = new int[g.V];
    for (int i = 0; i < g.V; i++) {
        g.visited[i] = false;
        g.pred[i] = -1;
    }

    g.topoSortDFS();
    g.topoSortBFS();

    return 0;
}
