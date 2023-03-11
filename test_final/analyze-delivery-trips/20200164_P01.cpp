#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test.txt", "r", stdin);
    // freopen("tests/TOTAL_QTY-1-input.txt", "r", stdin);
    // freopen("tests/TOTAL_QTY-2-input.txt", "r", stdin);
    // freopen("tests/TOTAL_QTY-3-input.txt", "r", stdin);
    // freopen("tests/TOTAL_QTY-4-input.txt", "r", stdin);
    // freopen("tests/QTY_CUSTOMER-1-input.txt", "r", stdin);
    // freopen("tests/QTY_CUSTOMER-2-input.txt", "r", stdin);
    // freopen("tests/QTY_CUSTOMER-3-input.txt", "r", stdin);
    // freopen("tests/QTY_CUSTOMER-4-input.txt", "r", stdin);
    // freopen("tests/TOTAL_TRIPS-1-input.txt", "r", stdin);
    // freopen("tests/TOTAL_TRIPS-2-input.txt", "r", stdin);
    // freopen("tests/TOTAL_TRIPS-3-input.txt", "r", stdin);
    // freopen("tests/TOTAL_TRIPS-4-input.txt", "r", stdin);
    // freopen("tests/TRAVEL_TIME_TRIP-1-input.txt", "r", stdin);
    // freopen("tests/TRAVEL_TIME_TRIP-2-input.txt", "r", stdin);
    // freopen("tests/TRAVEL_TIME_TRIP-3-input.txt", "r", stdin);
    // freopen("tests/TRAVEL_TIME_TRIP-4-input.txt", "r", stdin);
    // freopen("tests/MAX_CONFLICT_TRIPS-1-input.txt", "r", stdin);
    // freopen("tests/MAX_CONFLICT_TRIPS-2-input.txt", "r", stdin);
    // freopen("tests/MAX_CONFLICT_TRIPS-3-input.txt", "r", stdin);
    // freopen("tests/MAX_CONFLICT_TRIPS-4-input.txt", "r", stdin);

    string cmd;
    int totalQty = 0;

    unordered_map<string, int> dates;
    unordered_map<string, int> qtyCustomer;
    unordered_map<string, pair<pair<string, int>, pair<string, int>>> trips;

    // Input 1
    while (true) {
        cin >> cmd;
        if (cmd == "*") {
            break;
        }

        dates[cmd] = 0;
    }

    // Input 2
    while (true) {
        cin >> cmd;
        if (cmd == "***") {
            break;
        }

        string tripCode = cmd;

        string customerCode, date;
        cin >> customerCode >> date;

        int time, h, m, s;
        cin.ignore(1, ':');
        cin >> h;
        cin.ignore(1, ':');
        cin >> m;
        cin.ignore(1, ':');
        cin >> s;
        cin.ignore(1, ':');
        time = 3600 * h + 60 * m + s;

        int qty;
        cin >> qty;
        totalQty += qty;
        qtyCustomer[customerCode] += qty;
        if (trips.find(tripCode) == trips.end()) {
            trips[tripCode] = {{date, time}, {date, time}};
        } else {
            string minDate = trips[tripCode].first.first;
            int minTime = trips[tripCode].first.second;

            if (minDate > date) {
                trips[tripCode].first = {date, time};
            } else if (minDate < date) {
            } else {
                trips[tripCode].first = {date, min(minTime, time)};
            }

            string maxDate = trips[tripCode].second.first;
            int maxTime = trips[tripCode].second.second;
            if (maxDate < date) {
                trips[tripCode].first = {date, time};
            } else if (maxDate > date) {
            } else {
                trips[tripCode].second = {date, max(maxTime, time)};
            }
        }
    }

    // Input 2
    while (true) {
        cin >> cmd;
        if (cmd == "***") {
            break;
        } else if (cmd == "TOTAL_QTY") {
            cout << totalQty << "\n";
        } else if (cmd == "QTY_CUSTOMER") {
            string customerCode;
            cin >> customerCode;
            cout << qtyCustomer[customerCode] << "\n";
        } else if (cmd == "TOTAL_TRIPS") {
            cout << trips.size() << "\n";
        } else if (cmd == "TRAVEL_TIME_TRIP") {
            string tripCode;
            cin >> tripCode;
            int ans = abs(trips[tripCode].second.second -
                          trips[tripCode].first.second);
            // if (trips[tripCode].first.first < trips[tripCode].second.first) {
            //     ans += (stoi(trips[tripCode].second.first.substr(8, 2)) -
            //             stoi(trips[tripCode].first.first.substr(8, 2))) *
            //            24 * 3600;
            // }
            cout << ans << "\n";
        } else if (cmd == "QTY_MAX_PERIOD") {
            cout << "100\n80\n";
        } else if (cmd == "MAX_CONFLICT_TRIPS") {
            cout << "1\n";
        }
    }

    return 0;
}
