#include <bits/stdc++.h>
using namespace std;
using llg = long long;
const int maxN = 1e6;
int N;
llg M;
int heights[maxN];

llg sumCut(int H) {
    llg sum = 0;
    for (int i = 0; i < N; i++) {
        if (heights[i] >= H) {
            sum += heights[i] - H;
        }
    }
    return sum;
}

int binarySearch(int minH, int maxH, llg target) {
    while (minH <= maxH) {
        int H = (minH + maxH) / 2;
        llg sum = sumCut(H);
        if (sum == target) {
            return H;
        } else if (sum < target) {
            maxH = H - 1;
        } else {
            minH = H + 1;
        }
    }
    return minH - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("eko1.txt", "r", stdin);
    // freopen("eko2.txt", "r", stdin);

    cin >> N >> M;
    int maxHeight = -1;
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
        if (maxHeight < heights[i]) {
            maxHeight = heights[i];
        }
    }

    cout << binarySearch(0, maxHeight, M) << "\n";
    return 0;
}
