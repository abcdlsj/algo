#include <iostream>
#include <vector>
using namespace std;

vector<int> fa;
vector<int> ra;
int cnt;

int find(int x) {
    if (x != fa[x]) {
        fa[x] = find(fa[x]);
    }

    return fa[x];
}

void unionset(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y)
        return;
    if (ra[x] > ra[y]) {
        swap(x, y);
    }
    ra[y] += ra[x];
    fa[x] = fa[y];
    cnt--;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        if (m == 0 && n == 0)
            break;
        fa.resize(n);
        for (int i = 0; i < n; i++)
            fa[i] = i;
        ra.resize(n, 1);

        while (m--) {
            int k, a;
            cin >> k >> a;
            k--;
            while (k--) {
                int b;
                cin >> b;
                unionset(a, b);
            }
        }
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (find(0) == find(i)) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}