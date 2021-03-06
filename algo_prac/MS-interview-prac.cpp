#include <bits/stdc++.h>
using namespace std;
//
// 作者：hooa
// 链接：https://www.nowcoder.com/discuss/420669
// 来源：牛客网

// 算法题：给一个不含重复元素的数组，如果该数组满足下面两个条件中的任意一个，就返回true，否则返回false；
// 条件1：如果在该数组中可以找到两个数字使得交换这两个数字后的整个数组变为升序，那么该条件满足。
// 条件2：如果该数组中可以找到一个连续的子数组使得反转这个子数组后整个数组变为升序，那么该条件满足。

bool judge_arr(vector<int> arr) {
    int le = -1, ri = -1;

    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i - 1] > arr[i]) {
            if (le == -1) {
                le = i - 1;
            } else if (arr[i + 1] > arr[i]) {
                if (ri == -1) {
                    ri = i;
                } else {
                    return false;
                }
            }
        }
    }

    if (ri == -1) {
        ri = arr.size() - 1;
    }

    while (le < ri) {
        swap(arr[le], arr[ri]);
        le++, ri--;
    }

    return is_sorted(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 12, 11, 7, 6};
    if (judge_arr(arr)) {
        cout << "yes" << endl;
    }
}