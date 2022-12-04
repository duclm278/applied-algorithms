#include <bits/stdc++.h>

int solve1(int streets[], int numStreet) {
    int min = INT_MAX;
    for (int i = 0; i < numStreet; i++) {
        int sum = 0;
        for (int j = 0; j < numStreet; j++) {
            if (i != j) sum += abs(streets[i] - streets[j]);
        }

        if (min > sum) min = sum;
    }

    return min;
}

int solve2(int streets[], int numStreet) {
    std::sort(streets, streets + numStreet);

    int sum = 0;
    int median = streets[numStreet / 2];
    for (int i = 0; i < numStreet; i++) {
        sum += abs(streets[i] - median);
    }

    return sum;
}

int main() {
    freopen("vito_s_family.txt", "r", stdin);
    int numTest = 0;
    std::cin >> numTest;
    for (int i = 0; i < numTest; i++) {
        int numStreet = 0;
        std::cin >> numStreet;
        int streets[numStreet];
        for (int j = 0; j < numStreet; j++) {
            std::cin >> streets[j];
        }

        int result = 0;
        // result = solve1(streets, numStreet);
        result = solve2(streets, numStreet);

        std::cout << result << "\n";
    }
}
