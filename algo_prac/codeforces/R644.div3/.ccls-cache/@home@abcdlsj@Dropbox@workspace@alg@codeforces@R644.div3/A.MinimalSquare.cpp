#include <bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while (t--) {
        int a, b, area;
        cin >> a >> b;
        if (a < b) swap(a, b);
        area = pow(max(a, 2 * b), 2);
        cout << area << endl;
    }
}