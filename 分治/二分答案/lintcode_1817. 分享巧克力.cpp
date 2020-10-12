#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /**
     * @param sweetness: an integer array
     * @param K: an integer
     * @return:  return the maximum total sweetness of the piece
     */
    int maximizeSweetness(vector<int> &sweetness, int K) {
        // write your code here
        if (K >= sweetness.size())
            return 0;
        int le = *min_element(sweetness.begin(), sweetness.end()),
            ri = accumulate(sweetness.begin(), sweetness.end(), 0);

        while (le < ri) {
            int mid = le + (ri - le + 1) / 2;
            // cout << le << " " << ri << " " << mid << endl;
            if (check(sweetness, mid, K + 1)) {
                le = mid;
            } else {
                ri = mid - 1;
            }
        }

        return le;
    }

    bool check(vector<int> &s, int target, int k) {
        int cur = 0, sum = 0;

        for (int i = 0; i < s.size(); i++) {
            sum += s[i];
            if (sum >= target) {
                sum = 0;
                cur++;
            }
        }

        return cur >= k;
    }
};