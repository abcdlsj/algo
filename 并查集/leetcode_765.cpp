#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt;
    vector<int> fa, ra;
    int find(int x) {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }
    void unionset(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return ;
        if (ra[x] > ra[y]) swap(x, y);
        ra[y] += ra[x], fa[x] = fa[y];
        cnt--;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), m = n / 2;
        fa.resize(n);
        ra.resize(n, 1);
        cnt = m;
        for (int i = 0; i < n; i++) fa[i] = i;
        for (int i = 0; i < n; i += 2) {
            unionset(row[i] / 2, (row[i + 1]) / 2);
        }
        return m - cnt;
    }
};

int main() {}