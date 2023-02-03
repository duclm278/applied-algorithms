#include <bits/stdc++.h>

using namespace std;
const long N = 1e5 + 7;
const long INF = 1e9 + 7;
const long MODULE = 1e9 + 7;
typedef pair<int, int> ii;

int n, m;
int p[N], isArticulationPoint[N], isBridge[N], num[N], low[N],
    child[N];      // child[v]: number of children of v
vector<int> a[N];  // a[v]: list of adjacent vertices of v
int t;             // t: time point

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u) {
    t++;
    num[u] = t;
    low[u] = num[u];
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];  // v is adjacent vertex of u
        if (v == p[u]) continue;
        if (num[v]) {  // (u, v) is back edge (v is visited)
            low[u] = min(low[u], num[v]);
        } else {  // v is not visited
            p[v] = u;
            dfs(v);
            // Finish exploring v and all its descendants
            low[u] = min(low[u], low[v]);
        }
    }
}

int main() {
    input();
    int ansArticulationPoints = 0, ansBridges = 0;
    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        int v = p[i];
        if (v > 0) child[v]++;
    }
    for (int i = 1; i <= n; i++) {
        int u = p[i];
        if (u > 0 && p[u] > 0 && low[i] >= num[u]) {
            isArticulationPoint[u] = 1;  // u is articulation point
        }
    }
    for (int i = 1; i <= n; i++) {
        // p[i] == 0: i is root of DFS tree
        if (p[i] == 0 && child[i] >= 2) {
            isArticulationPoint[i] = 1;  // i is articulation point
        }
    }
    for (int i = 1; i <= n; i++) {
        if (isArticulationPoint[i]) ansArticulationPoints++;
    }
    for (int i = 1; i <= n; i++) {
        // low[i] > num[p[i]]: (p[i], i) is bridge
        if (p[i] != 0 && low[i] > num[p[i]]) {
            ansBridges++;
        }
    }
    cout << ansArticulationPoints << " " << ansBridges << "\n";
    return 0;
}
