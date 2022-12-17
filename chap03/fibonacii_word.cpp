#include <bits/stdc++.h>

using namespace std;

string g1, g2;
int N, I;
const int maxN = 1e6;
int fibonacci[maxN]{};

int findLengthTerm(int k) {
    if (fibonacci[k] == 0) {
        fibonacci[k] = findLengthTerm(k - 2) + findLengthTerm(k - 1);
    }
    return fibonacci[k];
}

char getFibonacci(int n, int i) {
    while (n > 2) {
        if (i <= findLengthTerm(n - 2)) {
            i = i;
            n = n - 2;
        } else {
            i = i - findLengthTerm(n - 1);
            n = n - 1;
        }
    }
    if (n == 1) return g1[i];
    return g2[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> g1 >> g2;
    fibonacci[1] = g1.size();
    fibonacci[2] = g2.size();
    cin >> N >> I;
    cout << getFibonacci(N, I);
    return 0;
}
