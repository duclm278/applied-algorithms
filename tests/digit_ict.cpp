#include <bits/stdc++.h>

using namespace std;

int N;
int c[8];
int mem[10];
int cnt = 0;

bool check() {
    int ict = c[1] * 100 + c[2] * 10 + c[3];
    int k62 = c[7] * 100 + 62;
    int hust = c[4] * 1000 + c[5] * 100 + c[6] * 10 + c[3];
    int f = ict - k62 + hust;
    return f == N;
}

void Try(int k) {
    // Sk = { 1 -> 9 }
    for (int y = 1; y <= 9; y++) {
        if (!mem[y]) {
            continue;
        }
        c[k] = y;
        mem[y] = 1;
        if (k == 7) {
            if (check()) {
                cnt++;
            }
        } else {
            Try(k + 1);
        }
        mem[y] = 0;
    }
}

int main() {
    std::cin >> N;
    Try(1);
    cout << cnt << "\n";
    return 0;
}
