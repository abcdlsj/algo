#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if (pages.size() == 0) return 0;
        int le = *max_element(pages.begin(), pages.end()), ri = accumulate(pages.begin(), pages.end(), 0);
        
        while (le < ri) {
            int mid = le + (ri - le) / 2;
            cout << le << " " << ri << " " << mid << endl;
            if (check(pages, mid, k)) {
                ri = mid;
            } else {
                le = mid + 1;
            }
        }
        
        return le;
    }
    bool check(const vector<int>& pages, int time, int k) {
        int cur = 1, sum = 0;
        for (int i = 0; i < pages.size(); i++) {
            sum += pages[i];
            if (sum > time) {
                sum = pages[i];
                cur++;
            }
        }
        
        return cur <= k;
    }
};