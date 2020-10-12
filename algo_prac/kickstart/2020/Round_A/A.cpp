#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    int time = 1;
    while (time <= T) {
        int N, B;
        cin >> N >> B;
        vector<int> costs(N, 0);
        for (int i = 0; i < N; i++)
            cin >> costs[i];

        sort(costs.begin(), costs.end());
        int ans = 0;
        for (auto &e : costs) {
            if (B >= e) {
                ans++;
                B -= e;
            }
        }
        cout << "Case #" << time << ": " << ans << endl;
        time++;
    }
}