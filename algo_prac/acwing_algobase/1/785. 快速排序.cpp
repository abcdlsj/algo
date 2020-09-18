#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& arr, int begin, int end) {
    if (begin >= end) return;
    int le = begin - 1, ri = end + 1, x = arr[(begin + end) >> 1];
    while (le < ri) {
        do
            le++;
        while (arr[le] < x);
        do
            ri--;
        while (arr[ri] > x);
        if (le < ri) swap(arr[le], arr[ri]);
    }
    quick_sort(arr, begin, ri), quick_sort(arr, ri + 1, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}