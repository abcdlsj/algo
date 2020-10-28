#include <bits/stdc++.h>
using namespace std;

int maxLcs(string s) {
    if (s.size() == 0) {
        return 0;
    }
    int len = s.size() * 2 + 1, maxn = 0, ri = -1, c = -1;
    vector<char> chaArr(len);
    vector<int> pArr(len, 0);
    for (int i = 0, idx = 0; i < len; i++) {
        chaArr[i] = (i & 1) == 0 ? '#' : s[idx++];
    }
    for (int i = 0; i < len; i++) {
        pArr[i] = i < ri ? min(ri - i, pArr[2 * c - i]) : 1;
        // 开始边界匹配
        while (i + pArr[i] < len && i - pArr[i] >= 0 &&
               chaArr[i + pArr[i]] == chaArr[i - pArr[i]]) {
            pArr[i]++;
        }
        if (i + chaArr[i] > ri) {
            ri = i + chaArr[i];
            c = i;
        }

        maxn = max(maxn, pArr[i]);
    }
    return maxn - 1;
}
int main() {
    string s1 = "abbbca";
    cout << maxLcs(s1) << endl;
}