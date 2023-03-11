#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test-public/2-input.txt", "r", stdin);
    input();
    while (true) {
        string command;
        cin >> command;
        if (command == "*") {
            break;
        }
        if (command == "insert") {
            int x;
            cin >> x;
            pq.push(x);
        } else if (command == "delete-max") {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}
