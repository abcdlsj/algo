class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), max_e = *max_element(bloomDay.begin(), bloomDay.end());
        if (m * k > n) return -1;
        int le = 0, ri = max_e;

        while (le < ri) {
            int mid = le + (ri - le) / 2;
            cout << mid << " " << le << " " << ri << " \\";
            if (check(bloomDay, mid, m, k)) {
                ri = mid;
                cout << "ri" << endl;
            } else {
                le = mid + 1;
                cout << "le" << endl;
            }
        }

        if (le == max_e && !check(bloomDay, max_e, m, k)) return -1;
        return le;
    }

    bool check(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0, cur = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cur++;
            } else {
                cur = 0;
            }
            if (cur == k) {
                count++;
                cur = 0;
            }
            if (count >= m) return true;
        }

        return false;
    }
};