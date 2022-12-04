#include <bits/stdc++.h>

int main() {
    freopen("just_prune_the_list.txt", "r", stdin);
    int numTest = 0;
    std::cin >> numTest;

    for (int i = 0; i < numTest; i++) {
        std::map<int, int> diff;

        int list1Size = 0;
        int list2Size = 0;
        std::cin >> list1Size >> list2Size;

        int x = 0;
        for (int j = 0; j < list1Size; j++) {
            std::cin >> x;
            diff[x]++;
        }

        for (int j = 0; j < list2Size; j++) {
            std::cin >> x;
            diff[x]--;
        }

        // int totalDiff = 0;
        // for (auto j : diff) {
        //     totalDiff += abs(j.second);
        // }

        int totalDiff = 0;
        for (std::map<int, int>::iterator it = diff.begin(); it != diff.end();
             it++) {
            totalDiff += abs(it->second);
        }

        std::cout << totalDiff << "\n";
    }

    return 0;
}
