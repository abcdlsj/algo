#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    vector<string> strs;
    while (cin >> s) {
        strs.push_back(s);
        if (cin.get() == '\n') {
            for (int i = 0; i < strs.size() - 1; i++) {
                cout << strs[i] << " ";
            }
            cout << strs.back() << endl;
            strs.clear();
        }
    }
}