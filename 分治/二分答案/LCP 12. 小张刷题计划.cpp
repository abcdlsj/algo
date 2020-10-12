#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minTime(vector<int> &time, int m) {
        int n = time.size(), sum = accumulate(time.begin(), time.end(), 0),
            max_e = *max_element(time.begin(), time.end());
        int le = max_e, ri = sum;
        while (le < ri) {
            int mid = le + (ri - le) / 2;
            if (check(time, m, mid)) {
                ri = mid;
            } else {
                le = mid + 1;
            }
        }
        return le;
    }

    bool check(vector<int> &time, int m, int target) {
        int count = 0, cur = 0, max_e = INT_MIN;
        for (int i = 0; i < time.size(); i++) {
            cur += time[i];
            max_e = max(max_e, time[i]);
            if (cur - max_e == target) {
                cur = 0;
                max_e = INT_MIN;
                count++;
            } else if (cur - max_e > target) {
                cur = time[i];
                max_e = time[i];
                count++;
            }
            if (cur > m)
                return false;
        }
        if (cur > 0)
            count++;
        return count <= m;
    }
};