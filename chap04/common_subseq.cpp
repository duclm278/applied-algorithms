#include <bits/stdc++.h>
using namespace std;
string a;
string b;
int mem[100][100];

int lcs(int i, int j) {
    if (i == -1 || j == -1) return 0;
    if (mem[i][j] != -1) return mem[i][j];
    if (a[i] == b[j])
        mem[i][j] = lcs(i - 1, j - 1) + 1;
    else
        mem[i][j] = max(lcs(i, j - 1), lcs(i - 1, j));
    return mem[i][j];
}

void trace(int i, int j) {
    if (i == -1 || j == -1) return;
    if (a[i] == b[j] && mem[i][j] == mem[i - 1][j - 1] + 1) {
        trace(i - 1, j - 1);
        cout << a[i];
        return;
    }
    if (mem[i][j] == mem[i][j - 1]) {
        trace(i, j - 1);
        return;
    }
    if (mem[i][j] == mem[i - 1][j]) {
        trace(i, j - 1);
        return;
    }
    trace(i - 1, j - 1);
}

int main() {
    memset(mem, -1, sizeof(mem));
    cout << "Enter string a: ";
    cin >> a;  // bananinn
    cout << "Enter string b: ";
    cin >> b;  // kaninan
    int m = a.length();
    int n = b.length();
    int ans = lcs(m - 1, n - 1);
    cout << "Found longest length: " << ans << "\n";  // 5

    // Trace using loop
    // TODO: Fix bugs: Loop found \0 5 times => Exit
    cout << "Found common subsequence: ";
    stack<char> s;
    for (int i = m - 1, j = n - 1, k = 0; k < ans;) {
        if (a[i] == b[j] && mem[i][j] == mem[i - 1][j - 1]) {
            s.push(a[i]);
            k++;
            cout << k;
            i--;
            j--;
            continue;
        }
        if (mem[i][j] == mem[i][j - 1]) {
            j--;
            continue;
        }
        if (mem[i][j] == mem[i - 1][j]) {
            i--;
            continue;
        }
        i--;
        j--;
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    // Trace using recursion
    // cout << "Found common subsequence: ";
    // trace(m - 1, n - 1);
    // cout << "\n";

    return 0;
}
