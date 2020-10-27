#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt;
vector<int> fa, ra;
int find(int x) {
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}
void unionset(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y)
        return;
    if (ra[x] > ra[y])
        swap(x, y);
    ra[y] += 1, fa[x] = y;
    cnt--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    while (cin >> n >> m) {
        fa.resize(n + 1, 0);
        ra.resize(n + 1, 1);

        
    }
}