#include <bits/stdc++.h>

void solve1(int prices[], int spans[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; i >= 0; j--) {
            if (prices[j] <= prices[i])
                spans[i]++;
            else
                break;
        }
    }
}

void solve2(int prices[], int spans[], int n) {
    std::stack<int> s;

    spans[0] = 0;
    s.push(0);

    for (int i = 1; i < n; i++) {
        while (!s.empty() && prices[s.top()] <= prices[i]) {
            s.pop();
        }

        if (s.empty())
            spans[i] = i;
        else
            spans[i] = i - s.top() - 1;

        s.push(i);
    }
}

int main() {
    freopen("stock_span.txt", "r", stdin);
    int n = 0;
    std::cin >> n;
    int prices[n];
    int spans[n];
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
        spans[i] = 0;
    }

    // solve1(prices, spans, n);
    solve2(prices, spans, n);

    for (int i = 0; i < n; i++) {
        std::cout << spans[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
