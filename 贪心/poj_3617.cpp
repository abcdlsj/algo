#include <iostream>
#include <vector>
#include <string>
#define MAX_N 100005
using namespace std;
typedef long long ll;

int N;
char s[MAX_N]; 

void solve() {
    int a = 0, b = N - 1, cnt = 0;
    while (a <= b) {
        bool left = false;
        for (int i = 0; a + i <= b; i++) {
            if (s[a + i] < s[b - i]) {
                left = true;
                break;
            } else if (s[a + i] > s[b - i]) {
                left = false;
                break;
            }
        }
        if (left) cout << s[a++];
        else cout << s[b--];
        if (++cnt == 80 && a <= b) {
            cnt = 0;
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> N) {
        for (int i = 0; i < N; i++) cin >> s[i];
        solve();
    }
}