#include <bits/stdc++.h>
using namespace std;
using llg = long long;
const int N = 1e6 + 1;
int n;
llg a[N];
llg S0[N];   // "% 2 == 0" subproblems
llg S1[N];   // "% 2 == 1" subproblems
bool B0[N];  // B0[i] = true means S0[i] exists.
bool B1[N];  // B1[i] = true means S1[i] exists.

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve() {
    if (a[1] % 2 == 0) {
        S0[1] = a[1];
        B0[1] = true;
        B1[1] = false;
    } else {
        S1[1] = a[1];
        B1[1] = true;
        B0[1] = false;
    }

    // Solve both S0[i], S1[i]
    for (int i = 2; i <= n; i++) {
        if (a[i] % 2 == 0) {
            if (B0[i - 1]) {
                if (S0[i - 1] > 0)
                    S0[i] = S0[i - 1] + a[i];
                else
                    S0[i] = a[i];
                B0[i] = true;
            } else {
                S0[i] = a[i];
                B0[i] = true;
            }

            if (B1[i - 1]) {
                S1[i] = S1[i - 1] + a[i];
                B1[i] = true;
            } else {
                B1[i] = false;
            }
        } else {
            if (B1[i - 1]) {
                S0[i] = S1[i - 1] + a[i];
                B0[i] = true;
            } else {
                B0[i] = false;
            }

            if (B0[i - 1]) {
                if (S0[i - 1] > 0)
                    S1[i] = S0[i - 1] + a[i];
                else
                    S1[i] = a[i];
                B1[i] = true;
            } else {
                S1[i] = a[i];
                B1[i] = true;
            }
        }
    }

    llg ans = -1e18;
    for (int i = 1; i <= n; i++) {
        if (B0[i] && ans < S0[i]) ans = S0[i];
    }
    cout << ans << "\n";
}

int main() {
    input();
    solve();
    return 0;
}
