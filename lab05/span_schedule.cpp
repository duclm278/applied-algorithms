#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
struct Arc {
    int v;                                 // Other end of arc
    int w;                                 // Weight of arc
    Arc(int _v, int _w) : v(_v), w(_w) {}  // Constructor
};
int n, m;
int duration[N];
vector<Arc> A[N];  // A[v]: set of outgoing arc of v
int d[N];          // Incoming degree
vector<int> L;     // Topological list
int F[N];          // F[v]: earliest possible starting time-point
int ans;

void input() {
    memset(d, 0, sizeof d);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> duration[i];
    for (int k = 1; k <= m; k++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(Arc(v, duration[u]));
        d[v]++;  // Increase incoming degree of v
    }
}

void topoSort() {
    queue<int> Q;
    // Add all vertices with incoming degree 0 to queue
    for (int v = 1; v <= n; v++)
        if (d[v] == 0) Q.push(v);
    // Use BFS variant to find topological list
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        L.push_back(x);  // Add x to end of topological list
        for (int i = 0; i < A[x].size(); i++) {
            int y = A[x][i].v;
            int w = A[x][i].w;
            d[y] -= 1;
            if (d[y] == 0) Q.push(y);
        }
    }
}

void solve() {
    memset(F, 0, sizeof F);
    ans = 0;
    for (int i = 0; i < L.size(); i++) {
        int u = L[i];
        ans = max(ans, F[u] + duration[u]);
        for (int j = 0; j < A[u].size(); j++) {
            int v = A[u][j].v;
            int w = A[u][j].w;
            F[v] = max(F[v], F[u] + w);
        }
    }
    cout << ans << "\n";
}

int main() {
    input();
    topoSort();
    solve();
}
