#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("top_signal1.txt", "r", stdin);

    int n;
    cin >> n;
    int a[n]{};

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i >= 2 && a[i - 1] > a[i - 2] && a[i - 1] > a[i]) {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
