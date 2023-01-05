#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int n;
int c[100][100];
int x[100];
int visited[100]{};
int f = 0;           // Final cost
int fopt = INT_MAX;  // Optimal final cost
int xopt[100];

void Try(int k) {
    // Sk = { 2 -> n } \ { x[2] -> x[k - 1] }; x[1] = 1
    for (int y = 2; y <= n; y++) {
        if (visited[y] == 0) {
            x[k] = y;
            visited[y] = 1;
            f += c[x[k - 1]][x[k]];
            if (k == n) {
                int f1 = f + c[x[n]][1];
                if (fopt > f1) {
                    fopt = f1;
                    for (int j = 1; j <= n; j++) {
                        xopt[j] = x[j];
                    }
                }
            } else {
                Try(k + 1);
            }
            f -= c[x[k - 1]][x[k]];
            visited[y] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("tsp10.txt", "r", stdin);
    // freopen("tsp15.txt", "r", stdin);
    // freopen("tsp20.txt", "r", stdin);
    // freopen("tsp30.txt", "r", stdin);
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    x[1] = 1;
    visited[1] = 1;
    for (int i = 2; i <= n; i++) {
        visited[i] = 0;
    }

    auto stime = high_resolution_clock::now();
    Try(2);
    auto etime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(etime - stime) / 1000.0;
    cout << "Time: " << duration.count() << "s"
         << "\n";

    // std::cout << "Optimal cost: " << fopt << "\n";
    // std::cout << "Optimal path: ";
    // for (int i = 1; i <= n; i++) {
    //     std::cout << xopt[i] << " -> ";
    // }
    // std::cout << xopt[1] << "\n";
    std::cout << fopt << "\n";
    return 0;
}
