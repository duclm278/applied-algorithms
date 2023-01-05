#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int a[N], S[N];
int n, L1, L2, ans;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve() {
    deque<int> d;  // Store index j of subproblem S[j]
    ans = 0;

    // L1 <= i - j <= L2
    for (int i = 1; i <= n; i++) {
        // Remove if d.front() < i - L2 <=> i - j > L2
        while (!d.empty() && d.front() < i - L2) d.pop_front();
        int j = i - L1;
        if (j >= 1) {
            // Increasing queue => d.back() must be highest.
            while (!d.empty() && S[d.back()] < S[j]) d.pop_back();
            d.push_back(j);
        }
        S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);
        ans = max(ans, S[i]);
    }
    cout << ans << "\n";
}

int main() {
    input();
    solve();
    return 0;
}
