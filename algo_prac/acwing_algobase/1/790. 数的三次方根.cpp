#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    double n; cin >> n;
    double le = -10000, ri = 10000;
    while (ri - le > 1e-8) {
        double mid = le + (ri - le) / 2;
        if (mid * mid * mid < n) {
            le = mid;
        } else {
            ri = mid;
        }
    }
    cout << fixed << setprecision(6) << le << "\n";
}