#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("books1.txt", "r", stdin);
    // freopen("books2.txt", "r", stdin);

    int n, t;
    cin >> n >> t;
    int time[n + 1]{};
    for (int i = 1; i <= n; i++) {
        cin >> time[i];
    }

    int maxBooks = 0;
    for (int i = 1; i <= n; i++) {
        int stime = 0;
        int booksRead = 0;
        for (int j = i; j <= n; j++) {
            stime += time[j];
            booksRead = j - i + 1;
            if (stime > t) {
                break;
            }
        }
        maxBooks = max(maxBooks, booksRead);
    }

    cout << maxBooks << "\n";
    return 0;
}
