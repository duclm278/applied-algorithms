#include <bits/stdc++.h>

using namespace std;

int n;
int A[1000000];
int M[20][1000000];

int rmq(int L, int R) {
    int k = log2(R - L + 1);
    int p2k = (1 << k);
    if (A[M[k][L]] <= A[M[k][R - p2k + 1]]) {
        return M[k][L];
    } else {
        return M[k][R - p2k + 1];
    }
}

void preprocess() {
    for (int i = 0; i < n; i++) {
        M[0][i] = i;
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            if (A[M[j - 1][i]] < A[M[j - 1][i + (1 << (j - 1))]]) {
                M[j][i] = M[j - 1][i];
            } else {
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
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
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    preprocess();

    int m = 0;
    scanf("%d", &m);
    int ans = 0;
    int L, R;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &L, &R);
        ans += A[rmq(L, R)];
    }
    cout << ans;
    return 0;
}
