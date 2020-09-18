#include <bits/stdc++.h>
using namespace std;

int cnt;
vector<int> father;
vector<int> ranks;
int findset(int x) {
    if (x != father[x]) {
        father[x] = findset(father[x]);
    }
    return father[x];
}
void unionset(int a, int b) {
    int x = findset(a), y = findset(b);
    if (x == y) return;
    if (ranks[x] > ranks[y]) {
        swap(x, y);
    }
    father[x] = y;
    ranks[y] += ranks[x];
    cnt--;
}
