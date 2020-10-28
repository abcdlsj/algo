#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MAX_N 10005
int T, N, M, S;
vector<int> G[MAX_N];
int D[MAX_N];

bool dfs(int v, int t) {
    D[v] = t;
    for (auto& e : G[v]) {
        if (D[e] == t) return false;
        else if (D[e] == 0 && !dfs(e, -t)) return false;
    }
    return true;
}

void solve() {
    cin >> N >> M >> S;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }
    for (int i = 0; i < N; i++) {
        if (D[i] == 0) {
            if (!dfs(i, 1)) {
                cout << "NO" << endl;
                break;
            }
        }
    }

    cout << "YES" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}
