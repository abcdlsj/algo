#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++)
      cin >> arr1[i];
    for (int i = 0; i < n; i++)
      cin >> arr2[i];

    int start1 = 0, end1 = n - 1, start2 = 0, end2 = n - 1, offset, mid1, mid2;

    while (start1 < end1) {
      mid1 = start1 + (end1 - start1) / 2;
      mid2 = start2 + (end2 - start2) / 2;
      offset = ((end1 - start1 + 1) & 1) ^ 1;
      if (arr1[mid1] > arr2[mid2]) {
        end1 = mid1;
        start2 = mid2 + offset;
      } else if (arr1[mid1] < arr2[mid2]) {
        start1 = mid1 + offset;
        end2 = mid2;
      } else {
        cout << arr1[mid1] << endl;
        return 0;
      }
    }

    cout << min(arr1[start1], arr2[start2]) << endl;
    return 0;
  }
}