#include <iostream>
#include <vector>
using namespace std;

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
    ra[y] += ra[x], fa[x] = y;
    cnt--;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int N, M;
        cin >> N >> M;
        fa.resize(N + 1);
        ra.resize(N + 1, 1);
        cnt = N;
        for (int i = 0; i <= N; i++)
            fa[i] = i;
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            unionset(a, b);
        }
        cout << cnt << "\n";
    }
    return 0;
}