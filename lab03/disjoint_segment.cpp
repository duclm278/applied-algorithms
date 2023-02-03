#include <bits/stdc++.h>
#define MaxN 100001
using namespace std;
int n;
pair<int, int> a[MaxN];  // a[i] -> segment
                         // a[i].first -> left coordinate
                         // a[i].second -> right coordinate

// Sort segments by second element of pairs
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
}

void solve() {
    int res = 0;   // Result
    int end = -1;  // End point of last chosen segment
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        if (a[i].first > end) {  // Not overlapping
            res++;
            end = a[i].second;
        }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    return 0;
}
