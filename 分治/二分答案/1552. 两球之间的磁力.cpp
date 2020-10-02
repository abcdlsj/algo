#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int le = 0, ri = position.back() - position[0];

        while (le < ri) {
            int mid = le + (ri - le + 1) / 2;
            if (check(position, mid, m)) {
                le = mid;
            } else {
                ri = mid - 1;
            }
        }

        return le;
    }
    bool check(vector<int>& position, int dis, int m) {
        int count = 1, prepos = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - prepos >= dis) {
                prepos = position[i];
                count++;
                if (count >= m) return true;
            }
        }

        return false;
    }
};