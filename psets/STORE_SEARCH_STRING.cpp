#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test.txt", "r", stdin);

    string str1, str2;
    unordered_set<string> db;

    while (true) {
        cin >> str1;
        if (str1 == "*") {
            break;
        }
        db.insert(str1);
    }

    while (true) {
        cin >> str1;
        if (str1 == "***") {
            break;
        }

        cin >> str2;
        auto p = db.find(str2);

        if (str1 == "find") {
            if (p != db.end())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        } else if (str1 == "insert") {
            if (p != db.end())
                cout << 0 << "\n";
            else {
                cout << 1 << "\n";
                db.insert(str2);
            }
        }
    }

    return 0;
}
