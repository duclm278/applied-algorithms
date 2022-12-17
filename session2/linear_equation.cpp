#include <bits/stdc++.h>
using namespace std;
#define N 20
int n, M;
int a[N];
int t[N];  // t[k] = a[1] + ... + a[k]
int X[N];  // Solution representation
int f;
int cnt;

bool check(int v, int k) {
    if (k < n) return true;
    return f + a[k] * v == M;
}

void solution() {
    cnt += 1;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "*" << X[i] << " ";
    }
    cout << M << "\n";
}

// Try values for X[k]
void Try(int k) {
    for (int v = 1; v <= (M - f - (t[n] - t[k])) / a[k]; v++) {
        if (check(v, k)) {
            X[k] = v;
            f = f + a[k] * X[k];
            if (k == n)
                solution();
            else
                Try(k + 1);
            f = f - a[k] * X[k];
        }
    }
}

void input() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void initT() {
    t[1] = a[1];
    for (int i = 2; i <= n; i++) {
        t[i] = t[i - 1] + a[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    initT();
    Try(1);
    cout << cnt << "\n";
    return 0;
}
