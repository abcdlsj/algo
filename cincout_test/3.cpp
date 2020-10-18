#include <bits/stdc++.h>
using namespace std;

// 输入 n 行字符串，输出它们，行间包含空格
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);

    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        cout << s << endl;
    }

    fclose(stdin);
    fclose(stdout);
}