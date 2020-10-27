#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 20005
typedef long long ll;
int n;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n) {
        ll ans = 0;
        priority_queue<int, vector<int>, greater<int>> pue;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            pue.push(x);
        }
        while (pue.size() > 1) {
            int a = pue.top(); pue.pop();
            int b = pue.top(); pue.pop();
            ans += a + b;
            pue.push(a + b);
        }
        cout << ans << endl;
    }
}