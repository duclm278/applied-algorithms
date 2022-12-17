// Enumerate all permutations of n elements
#include <bits/stdc++.h>

int n;
int a[100];
int used[100];

bool check(int y, int k) {
    for (int i = 1; i <= k - 1; i++) {
        if (y == a[i]) return false;
    }
    return true;
}

void solution() {
    for (int i = 1; i <= n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

void Try(int k) {
    // Sk = { 1, 2 -> n } \ { a[1], a[2] -> a[k - 1] }
    for (int y = 1; y <= n; y++) {
        if (check(y, k)) {
            a[k] = y;
            used[y] = 1;
            if (k == n)
                solution();
            else
                Try(k + 1);
            used[y] = 0;
        }
    }
}

int main() {
    std::cin >> n;
    Try(1);
    return 0;
}
