#include <bits/stdc++.h>
using namespace std;
#define N 5001
#define INF 1000000000
int w[N][N];  // w[u][v]: weight of arc(u, v)
int n, m;
int C[N], D[N];
int d[N];          // d[i]: distance from source to i during BFS
bool f[N];         // f[v] = true: found shortest path from s to v
vector<int> A[N];  // A[v]: list of adjacent cities of v

void BFS(int i) {
    queue<int> Q;
    for (int j = 1; j <= n; j++) d[j] = -1;
    d[i] = 0;
    Q.push(i);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        // cout << "BFS(" << i << ") POP v = " << v << "\n";
        w[i][v] = C[i];  // Weight of arc (i, v) is price of bus at city i.
        int size = A[v].size();
        for (int j = 0; j < size; j++) {
            int u = A[v][j];
            if (d[u] >= 0) continue;  // Continue if u has been visited
            d[u] = d[v] + 1;
            if (d[u] <= D[i]) Q.push(u);
            // cout << "BFS(" << i << ") PUSH u = " << u << "\n";
        }
    }
}

void buildGraph() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) w[i][j] = INF;
    for (int i = 1; i <= n; i++) {
        BFS(i);
    }
}

void dijkstra(int s, int t) {
    for (int v = 1; v <= n; v++) {
        d[v] = w[s][v];
        f[v] = false;
    }
    d[s] = 0;
    f[s] = true;
    for (int i = 1; i <= n; i++) {
        int u = -1;
        int minD = INF;
        // Select node u having minimum d[u]
        for (int v = 1; v <= n; v++)
            if (!f[v]) {
                if (d[v] < minD) {
                    u = v;
                    minD = d[v];
                }
            }
        f[u] = true;
        if (u == t) break;  // Result found
        for (int v = 1; v <= n; v++)
            if (!f[v]) {
                if (d[v] > d[u] + w[u][v]) {
                    d[v] = d[u] + w[u][v];
                }
            }
    }
    cout << d[t];
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void solve() {
    buildGraph();
    dijkstra(1, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    return 0;
}
