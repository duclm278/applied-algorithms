// Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị
// nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj
// = M.
//
// Dữ liệu
// Dòng 1: ghi n và M (1 <= n, M <= 1000000)
// Dòng 2: ghi a1, a2, ..., an
// Kết quả
// Ghi ra giá trị Q
// Ví dụ
// Dữ liệu
// 5 6
// 5 2 1 4 3
// Kết quả
// 2

#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt{0};
int a[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test.txt", "r", stdin);

    cin >> n >> m;
    unordered_set<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (s.find(a[i]) == s.end()) {
            s.insert(a[i]);
        }

        if (s.find(m - a[i]) != s.end() && m - a[i] != a[i]) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
