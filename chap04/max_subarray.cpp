#include <bits/stdc++.h>

using namespace std;

int a[100];
int mem[100]{};  // Max sum ending at a[i]
int solved[100]{0};

// Max sum ending at a[i]
int maxSum(int i) {
    if (i == 1) return a[1];
    if (solved[i]) return mem[i];
    mem[i] = max(mem[i - 1] + a[i], a[i]);
    solved[i] = 1;
    return mem[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test.txt", "r", stdin);

    int n;
    cin >> n;
    int ans = INT_MIN;
    int endIndex = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int curMaxSum = maxSum(i);
        if (ans < curMaxSum) {
            ans = curMaxSum;
            endIndex = i;
        }
    }

    cout << ans << "\n";
    int i = endIndex;
    for (; i >= 1; i--) {
        ans -= a[i];
        if (ans == 0) {
            break;
        }
    }

    for (; i <= endIndex; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}
