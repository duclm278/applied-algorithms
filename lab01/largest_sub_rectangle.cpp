#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3;
int n, m;
int A[maxN][maxN];

int maxHistogram(int row[]) {
    // A stack holds indexes of hist[] array. The bars stored in stack are
    // always in increasing order of their heights.
    stack<int> st;
    int topValue;
    int maxArea = 0;
    int curArea = 0;

    int i = 0;
    while (i < m) {
        if (st.empty() || row[st.top()] <= row[i]) {
            st.push(i++);
        } else {
            topValue = row[st.top()];
            st.pop();
            curArea = topValue * i;
            if (!st.empty()) {
                curArea = topValue * (i - st.top() - 1);
            }
            maxArea = max(curArea, maxArea);
        }
    }

    // Pop the remaining bars
    while (!st.empty()) {
        topValue = row[st.top()];
        st.pop();
        curArea = topValue * i;
        if (!st.empty()) {
            curArea = topValue * (i - st.top() - 1);
        }
        maxArea = max(curArea, maxArea);
    }
    return maxArea;
}

int maxRectangle() {
    int ans = maxHistogram(A[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 1) {
                A[i][j] += A[i - 1][j];
            }
        }
        ans = max(ans, maxHistogram(A[i]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("largest1.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    cout << maxRectangle();
    return 0;
}
