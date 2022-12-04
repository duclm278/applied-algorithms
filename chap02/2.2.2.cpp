// Enumerate all m-element subsets of the set of n-element
#include <bits/stdc++.h>

int n, m;
int a[100];

void printSolution() {
    for (int i = 1; i <= m; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

void Try(int k) {
    // Sk = { a[k - 1] + 1, a[k - 1] + 2 -> n - m + k }
    for (int y = a[k - 1] + 1; y <= n - m + k; y++) {
        a[k] = y;
        if (k == m)
            printSolution();
        else
            Try(k + 1);
    }
}

int main() {
    std::cin >> n >> m;
    Try(1);
    return 0;
}
