#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    vector<string> strs;

    // stringstream 分割
    // while (cin >> s) {
    //     stringstream ss(s);
    //     while (getline(ss, s, ',')) {
    //         strs.push_back(s);
    //     }
    //     sort(strs.begin(), strs.end());
    //     for (int i = 0; i < strs.size() - 1; i++) {
    //         cout << strs[i] << ",";
    //     }
    //     cout << strs.back() << endl;
    //     strs.clear();
    // }
    // 
    while (cin >> s) {
        string tmp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ',') {
                tmp += s[i];
            } else {
                strs.push_back(tmp);
                tmp = "";
            }
        }
        strs.push_back(tmp);
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs.size() - 1; i++) cout << strs[i] << ","; cout << strs.back() << endl;
        strs.clear();
    }
}