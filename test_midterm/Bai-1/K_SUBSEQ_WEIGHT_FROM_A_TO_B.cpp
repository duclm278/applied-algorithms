#include <bits/stdc++.h>
using namespace std;
int n, k, A, B;
int a[100005];
int cnt = 0;

void solve() {
    cin >> n >> k >> A >> B;
    int currentSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        currentSum += a[i];

        // Use old sum to get new sum
        if (i >= k) {
            currentSum -= a[i - k];
        }

        // Check if currentSum is in range [A, B]
        if (i >= k - 1 && currentSum >= A && currentSum <= B) {
            cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test-public/4-input.txt", "r", stdin);
    solve();
    cout << cnt << "\n";
}
