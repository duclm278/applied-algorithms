#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define NMAX 122

int n, cost = 0, f_opt = INT_MAX, c_min = INT_MAX;
int a[NMAX], a_opt[NMAX];
int c[NMAX][NMAX];

bool check(int i, int j) {
    for (int k = i; k >= 1; k--)
        if (a[k] == j) return false;
    return true;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (check(k, i)) {
            a[k] = i;
            int dist = (k == 1) ? c[0][a[k]] : c[a[k - 1] + n][a[k]];
            cost += dist + c[a[k]][a[k] + n];
            if (k == n) {
                int f = cost + c[a[k] + n][0];
                if (f_opt > f) {
                    f_opt = f;
                    for (int i = 1; i <= n; i++) a_opt[i] = a[i];
                }
            } else if (f_opt > cost + (2 * (n - k) + 1) * c_min)
                Try(k + 1);
            cost -= dist + c[a[k]][a[k] + n];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("taxi.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j && c[i][j] < c_min) c_min = c[i][j];
        }
    a[0] = 0;
    a_opt[0] = 0;

    auto stime = high_resolution_clock::now();
    Try(1);
    auto etime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(etime - stime);
    cout << "Time: " << duration.count() << " ms"
         << "\n";

    // for (int i = 0; i <= n; i++) {
    //     cout << a_opt[i] << " -> ";
    //     if (i > 0) cout << a_opt[i] + n << " -> ";
    // }
    // cout << 0 << "\n";
    cout << f_opt << "\n";
}
