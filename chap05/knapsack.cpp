#include <bits/stdc++.h>
using namespace std;

// A utility function that returns maximum of two integers.
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W.
int knapSack(int W, int wt[], int vl[], int n) {
    // Base Case
    if (n == 0 || W == 0) return 0;

    // If weight of the nth item is more than Knapsack capacity W, then this
    // item cannot be included in the optimal solution.
    if (wt[n - 1] > W) return knapSack(W, wt, vl, n - 1);

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) nth item not included
    else
        return max(vl[n - 1] + knapSack(W - wt[n - 1], wt, vl, n - 1),
                   knapSack(W, wt, vl, n - 1));
}

int main() {
    int n;
    cin >> n;

    // vl = {60, 100, 120}
    int vl[n];
    for (int i = 0; i < n; i++) {
        cin >> vl[i];
    }

    // wt = {10, 20, 30};
    int wt[n];
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int W = 50;
    cout << knapSack(W, wt, vl, n);
    return 0;
}
