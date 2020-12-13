#include <bits/stdc++.h>
using namespace std;

// 谷歌面试题：输入是两个整数数组，他们任意两个数的和又可以组成一个数组，求这个和中前
// k 个数怎么做？

// TODO
const int maxn = 10005;
vector<int> arr1(maxn), arr2(maxn);
int main() {
    int k; cin >> k;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int m, n; // m, n 分别是 arr1， arr2 的长度
    vector<int> res;
    int i = 0, j = 0;

    while (k--) {
        auto a = arr1[i], b = arr2[j];
        res.push_back(a + b);
        if (i + 1 == m) {
            j++;
        } else if (j + 1 == n) {
            i++;
        } else {
            auto c = arr1[i + 1], d = arr2[j + 1];
            if (c < d) {
                i++;
            } else {
                d++;
            }
        }
    }

    return 0;
}