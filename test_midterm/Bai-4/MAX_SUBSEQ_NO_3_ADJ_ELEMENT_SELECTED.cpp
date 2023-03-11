#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
int sum[100005];  // sum[i]: maxSum of subsequence ending at arr[i]
int ans = -1;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    // Initialize sum for 1st 3 elements
    if (n >= 1) sum[0] = arr[0];
    if (n >= 2) sum[1] = arr[0] + arr[1];
    if (n >= 3) sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2]));

    // Get maxSum of different cases for remaining elements
    for (int i = 3; i < n; i++) {
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]),
                     sum[i - 3] + arr[i] + arr[i - 1]);
    }

    ans = sum[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test-public/4-input.txt", "r", stdin);
    input();
    solve();
    cout << ans << "\n";
    return 0;
}
