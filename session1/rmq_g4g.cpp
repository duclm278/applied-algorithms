#include <bits/stdc++.h>

using namespace std;

int n;
int A[1000000];
int M[1000000][20];

int rmq(int L, int R) {
    // For [2, 10], k = 3
    int k = log2(R - L + 1);
    int p2k = (1 << k);

    // For [2, 10], compare [2, 9] and [3, 10]
    // For [2, 10], compare A[M[2][3]] & A[M[3][3]]
    if (A[M[L][k]] <= A[M[R - p2k + 1][k]]) {
        return M[L][k];
    } else {
        return M[R - p2k + 1][k];
    }
}

void preprocess() {
    // Initialize M for intervals of size 1
    for (int i = 0; i < n; i++) {
        M[i][0] = i;
    }

    // Compute values from small to large intervals
    for (int j = 1; (1 << j) <= n; j++) {
        // Compute minimum value for intervals of size 2^j
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            // For [2, 10], compare [2, 9] and [3, 10]
            // For [2, 10], compare A[M[2][3]] & A[M[3][3]]
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]]) {
                M[i][j] = M[i][j - 1];
            } else {
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("rmq1.txt", "r", stdin);
    // freopen("rmq2.txt", "r", stdin);
    // freopen("rmq3.txt", "r", stdin);
    // freopen("rmq4.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    preprocess();

    int m = 0;
    cin >> m;
    int ans = 0;
    int L, R;
    for (int i = 0; i < m; i++) {
        cin >> L >> R;
        ans += A[rmq(L, R)];
    }
    cout << ans;
    return 0;
}
