#include <bits/stdc++.h>

using namespace std;

int mem[100]{-1};

int fibonacci(int n) {
    if (n <= 2) return 1;
    if (mem[n] != -1) return mem[n];
    mem[n] = fibonacci(n - 2) + fibonacci(n - 1);
    return mem[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test.txt", "r", stdin);
    return 0;
}
