#include <bits/stdc++.h>

using namespace std;

int isValid(string phoneNum) {
    int length = phoneNum.length();
    if (length != 10) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (phoneNum[i] < '0' || phoneNum[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("telco1.txt", "r", stdin);
    // freopen("telco3.txt", "r", stdin);

    string type, fnum, tnum, date;
    int h, m, s;
    int ftime, dtime;
    int allValid = 1;
    int totalCalls = 0;
    unordered_map<string, int> numberCalls, timeCalls;
    while (true) {
        cin >> type;
        if (type == "#") {
            break;
        }
        totalCalls++;
        cin >> fnum >> tnum >> date;
        if (!isValid(fnum) || !isValid(tnum)) {
            allValid = 0;
        }
        cin.ignore(1, ':');
        cin >> h;
        cin.ignore(1, ':');
        cin >> m;
        cin.ignore(1, ':');
        cin >> s;
        ftime = h * 3600 + m * 60 + s;
        cin.ignore(1, ':');
        cin >> h;
        cin.ignore(1, ':');
        cin >> m;
        cin.ignore(1, ':');
        cin >> s;
        dtime = h * 3600 + m * 60 + s - ftime;
        timeCalls[fnum] += dtime;
        numberCalls[fnum]++;
    }

    while (true) {
        cin >> type;
        if (type == "#") {
            break;
        } else if (type == "?check_phone_number") {
            if (allValid == true) {
                cout << "1\n";
            }
        } else if (type == "?number_calls_from") {
            cin >> fnum;
            cout << numberCalls[fnum] << "\n";
        } else if (type == "?number_total_calls") {
            cout << totalCalls << "\n";
        } else if (type == "?count_time_calls_from") {
            cin >> fnum;
            cout << timeCalls[fnum] << "\n";
        }
    }
    return 0;
}
