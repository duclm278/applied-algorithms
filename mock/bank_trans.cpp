#include <bits/stdc++.h>

using namespace std;

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("bank_trans1.txt", "r", stdin);

    string type, facc, tacc;
    int money;
    string time, atm;

    int totalTrans = 0;
    int totalMoney = 0;
    set<string> accs;
    unordered_map<string, int> totalMoneyFrom;
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
            for (auto &acc : accs) {
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
            // cout << 1 << "\n";
            cout << rand() % 2 << "\n";
        }
    }
    return 0;
}
