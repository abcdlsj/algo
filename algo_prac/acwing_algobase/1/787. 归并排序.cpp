#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int begin, int mid, int end) {
    int i = begin, j = mid + 1, idx = 0;
    vector<int> tmp(end - begin + 1);
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) tmp[idx++] = arr[i++];
        else tmp[idx++] = arr[j++];
    }
    while (i <= mid) tmp[idx++] = arr[i++];
    while (j <= end) tmp[idx++] = arr[j++];
    for (idx = 0, i = begin; i <= end; i++, idx++) arr[i] = tmp[idx];
}
void merge_sort(vector<int>& arr, int begin, int end) {
    if (begin >= end) return ;
    int mid = begin + (end - begin) / 2;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}