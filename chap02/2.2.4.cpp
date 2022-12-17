// The n-queen problem
#include <bits/stdc++.h>

int n, cnt;
int a[100];

bool check(int y, int k) {
    for (int i = 1; i <= k - 1; i++) {
        if (y == a[i] || abs(i - k) == abs(a[i] - y)) return false;
    }
    return true;
}

void solution() {
    for (int i = 1; i <= n; i++) {
        std::cout << "(" << i << ", " << a[i] << ") ";
    }
    std::cout << "\n";
    cnt++;
}

void Try(int k) {
    // Sk = { 1, 2 -> n } \ { { a[1], a[2] -> a[k - 1] }, { same diagonal } }
    for (int y = 1; y <= n; y++) {
        if (check(y, k)) {
            a[k] = y;
            if (k == n)
                solution();
            else
                Try(k + 1);
        }
    }
}

int main() {
    std::cin >> n;
    Try(1);
    if (cnt == 0) std::cout << "No solutions!\n";
    return 0;
}
