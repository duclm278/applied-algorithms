#include <bits/stdc++.h>

using namespace std;

int binarySearch(int sum[], int l, int r, int target) {
    // sum[j] <= target
    // sum[j] <= t + sum[i] - time[i]
    while (l <= r) {
        int m = (l + r) / 2;
        if (sum[m] == target) {
            return m;
        } else if (sum[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("books1.txt", "r", stdin);
    // freopen("books2.txt", "r", stdin);

    int n, t;
    cin >> n >> t;
    int sum[n + 1]{};  // sum[k] = time[1] + ... + time[k]
    int time[n + 1]{};
    for (int i = 1; i <= n; i++) {
        cin >> time[i];
        sum[i] = sum[i - 1] + time[i];
    }

    int maxRead = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int stime = 0;
        int curRead = 0;
        int j = binarySearch(sum, i, n, t + sum[i] - time[i]);
        curRead = j - i + 1;
        maxRead = max(maxRead, curRead);
    }

    cout << maxRead << "\n";
    return 0;
}
