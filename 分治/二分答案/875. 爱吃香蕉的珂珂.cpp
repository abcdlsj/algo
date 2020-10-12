#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minEatingSpeed(vector<int> &piles, int H) {
        int max_e = *max_element(piles.begin(), piles.end());

        int le = 1, ri = max_e;
        while (le < ri) {
            int mid = le + (ri - le) / 2;
            if (check(piles, mid, H)) {
                ri = mid;
            } else {
                le = mid + 1;
            }
        }

        return le;
    }
    bool check(vector<int> &piles, int speed, int h) {
        int count = 0;
        for (int i = 0; i < piles.size(); i++) {
            count += (piles[i] / speed);
            if (piles[i] % speed != 0)
                count++;
            if (count > h)
                return false;
        }
        return true;
    }
};