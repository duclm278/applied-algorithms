// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define MaxN 100001
using namespace std;
int t;
int n, c, a[MaxN];

// True if found subset of given set s.t. the distance == param distance
bool check(int distance) {
    int cnt = 1;  // Number of selected items s.t the distance >= param distance
    int i = 1, j = 2;
    while (i < n) {
        while (j <= n && a[j] - a[i] < distance) ++j;
        if (j <= n) cnt++;
        if (cnt >= c) return true;  // Enough to take c elements
        i = j;
        j++;
    }
    return false;
}

int maxDistance() {
    int l = 0, r = a[n] - a[1];
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m))
            l = m + 1;  // Search 1st half
        else
            r = m - 1;  // Search 2nd half
    }
    return r;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &c);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        printf("%d\n", maxDistance());
    }
}
