#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x;
    int y;
} Node;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("maze1.txt", "r", stdin);
    // freopen("maze2.txt", "r", stdin);
    // freopen("maze4.txt", "r", stdin);
    // freopen("maze5.txt", "r", stdin);

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--;
    c--;
    int walls[n][m];
    int steps[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> walls[i][j];
        }
    }

    queue<Node> fringe;
    int dx[] = {-1, +0, +0, +1};
    int dy[] = {+0, -1, +1, +0};

    // Initialize fringe to just the starting node
    fringe.push({r, c});
    walls[r][c] = 1;
    steps[r][c] = 0;

    while (!fringe.empty()) {
        // Choose a node from the fringe
        Node currNode = fringe.front();
        fringe.pop();

        // Add neighbors to fringe
        for (int i = 0; i < 4; i++) {
            int x = currNode.x + dx[i];
            int y = currNode.y + dy[i];
            if (x < 0 || x > n - 1 || y < 0 || y > m - 1) {
                cout << steps[currNode.x][currNode.y] + 1;
                return 0;
            }
            if (!walls[x][y]) {
                fringe.push({x, y});
                steps[x][y] = steps[currNode.x][currNode.y] + 1;
                walls[x][y] = 1;
            }
        }
    }

    // Found no solutions
    cout << -1;
    return 0;
}
