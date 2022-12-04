#include <bits/stdc++.h>

int x[100];
int M, n, M1;

void printSolution() {
    for (int i = 1; i <= n; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << "\n";
}

void Try(int k) {
    // Sk = { 1, 2 -> M - (n - k) - M1 }; M1 = x[1] + ... + x[k - 1]
    int U = M - M1 - (n - k);
    for (int y = 1; y <= U; y++) {
        x[k] = y;
        M1 += x[k];
        if (k == n) {
            if (M1 == M) printSolution();
        } else
            Try(k + 1);
        M1 -= x[k];
    }
}

int main() {
    M1 = 0;
    std::cin >> n;
    std::cin >> M;
    Try(1);
    return 0;
}
