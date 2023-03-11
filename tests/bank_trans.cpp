#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
typedef struct {
    string acc;
    unordered_set<string> currPath;
} Node;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("bank_trans8.txt", "r", stdin);

    string type, facc, tacc;
    int money;
    string time, atm;

    int totalTrans = 0;
    int totalMoney = 0;
    set<string> accs;
    unordered_map<string, int> totalMoneyFrom;
    unordered_map<string, set<string>> accToAccs;
    map<string, vector<pair<string, int>>> accToTrans;

    // Custom comparator for sorting by time
    auto cmp = [](const string& timestamp1, const string& timestamp2) {
        int h1 = stoi(timestamp1.substr(0, 2));
        int m1 = stoi(timestamp1.substr(3, 2));
        int s1 = stoi(timestamp1.substr(6, 2));
        int h2 = stoi(timestamp2.substr(0, 2));
        int m2 = stoi(timestamp2.substr(3, 2));
        int s2 = stoi(timestamp2.substr(6, 2));
        if (h1 != h2) {
            return h1 < h2;
        } else if (m1 != m2) {
            return m1 < m2;
        } else {
            return s1 < s2;
        }
    };
    map<string, int, decltype(cmp)> transMaxMoney;

    while (true) {
        cin >> type;
        if (type == "#") {
            break;
        }
        facc = type;
        cin >> tacc >> money >> time >> atm;
        totalTrans++;
        totalMoney += money;
        accs.insert(facc);
        accs.insert(tacc);
        totalMoneyFrom[facc] += money;
        accToAccs[facc].insert(tacc);
        if (transMaxMoney.find(time) == transMaxMoney.end()) {
            transMaxMoney[time] = money;
        } else {
            transMaxMoney[time] = max(transMaxMoney[time], money);
        }
    }

    while (true) {
        cin >> type;
        if (type == "#") {
            break;
        } else if (type == "?number_transactions") {
            cout << totalTrans << "\n";
        } else if (type == "?total_money_transaction") {
            cout << totalMoney << "\n";
        } else if (type == "?list_sorted_accounts") {
            string output = "";
            for (auto& acc : accs) {
                output += acc + " ";
            }
            output[output.length() - 1] = '\n';
            cout << output;
        } else if (type == "?total_money_transaction_from") {
            cin >> facc;
            cout << totalMoneyFrom[facc] << "\n";
        } else if (type == "?inspect_cycle") {
            int k;
            cin >> facc >> k;
            stack<Node> fringe;
            fringe.push({facc, unordered_set<string>({facc})});

            bool found = false;
            while (!fringe.empty()) {
                string currAcc = fringe.top().acc;
                unordered_set<string> currPath = fringe.top().currPath;
                int length = currPath.size();
                fringe.pop();

                for (auto& acc : accToAccs[currAcc]) {
                    // Exit if: acc (k) -> facc
                    if (length == k && acc == facc) {
                        cout << "1\n";
                        found = true;
                        break;
                    }

                    // Add to fringe if currently not in path
                    if (currPath.find(acc) == currPath.end()) {
                        // Exit early if: currAcc (k - 1) -> acc (k) -> facc
                        // if (length == k - 1 &&
                        //     accToAccs[acc].find(facc) !=
                        //     accToAccs[acc].end()) { cout << "1\n"; found =
                        //     true; break;
                        // }

                        // if (length < k - 1) {
                        //     unordered_set<string> newPath = currPath;
                        //     newPath.insert(acc);
                        //     fringe.push({acc, newPath});
                        // }

                        if (length < k) {
                            unordered_set<string> newPath = currPath;
                            newPath.insert(acc);
                            fringe.push({acc, newPath});
                        }
                    }
                }
                if (found) break;
            }
            if (!found) {
                cout << "0\n";
            }
        } else if (type == "?max_money_period") {
            int h1, m1, s1, h2, m2, s2;
            cin.ignore(1, ':');
            cin >> h1;
            cin.ignore(1, ':');
            cin >> m1;
            cin.ignore(1, ':');
            cin >> s1;
            cin.ignore(1, ':');
            cin >> h2;
            cin.ignore(1, ':');
            cin >> m2;
            cin.ignore(1, ':');
            cin >> s2;
        }
    }
    return 0;
}
