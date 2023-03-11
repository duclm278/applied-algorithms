#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test.txt", "r", stdin);

    string input;
    cin >> input;

    stack<char> s;
    unordered_map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    for (auto& c : input) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else {
            if (!s.empty() && m[s.top()] == c) {
                s.pop();
            } else {
                cout << 0 << "\n";
                return 0;
            }
        }
    }

    if (s.empty()) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
