#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int a[105];
int prevItemAtTry[105];
int cnt = 0;
int currentSum = 0;

void input() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void Try(int i) {
    for (int v = prevItemAtTry[i - 1] + 1; v <= n - k + i; v++) {
        prevItemAtTry[i] = v;
        currentSum += a[v];
        if (i == k) {
            if (currentSum == m) {
                cnt++;
            }
        } else {
            Try(i + 1);
        }
        currentSum -= a[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test-public/4-input.txt", "r", stdin);
    input();
    Try(1);
    cout << cnt << "\n";
}
