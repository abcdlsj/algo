#include <climits>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T; cin >> T;
    while (T--) {
        int len, n; cin >> len >> n;
        int mi = 0, ma = 0;
        while (n--) {
            int a; cin >> a;
            mi = max(mi, min(a, len - a));
            ma = max(ma, max(a, len - a));
        }
        cout << mi << " " << ma << endl;
    }
}