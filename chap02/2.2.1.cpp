// Enumerate all binary strings of length n
#include <bits/stdc++.h>

int n;
int a[100];

void solution() {
    for (int i = 1; i <= n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

void Try(int k) {
    // Sk = { 0, 1 }
    for (int y = 0; y <= 1; y++) {
        a[k] = y;
        if (k == n)
            solution();
        else
            Try(k + 1);
    }
}

int main() {
    std::cin >> n;
    Try(1);
    return 0;
}
