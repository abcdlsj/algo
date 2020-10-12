/*
 * @Author: abcdlsj
 * @Date: 2020-08-13 18:30:59
 * @Last Modified by: abcdlsj
 * @Last Modified time: 2020-08-13 20:00:29
 */

#include <iostream>
#include <vector>
using namespace std;

void sink(vector<int> &arr, int idx, int end) {
    int largestIdx = idx, left = idx * 2 + 1, right = idx * 2 + 2;
    if (left <= end && arr[largestIdx] < arr[left])
        largestIdx = left;
    if (right <= end && arr[largestIdx] < arr[right])
        largestIdx = right;
    if (largestIdx != idx) {
        swap(arr[largestIdx], arr[idx]);
        sink(arr, largestIdx, end);
    }
}
// 如果插入一个元素到最后，然后上浮到合适的位置
void swim(vector<int> &arr, int idx) {
    int p = (idx - 1) / 2;

    if (arr[idx] > arr[p]) {
        swap(arr[idx], arr[p]);
        swim(arr, p);
    }
}

void heapfully(vector<int> &arr) {
    for (int i = (arr.size() - 1) / 2; i >= 0; i--) {
        sink(arr, i, arr.size() - 1);
    }
}

void insert(vector<int> &arr, int ele) {
    arr.push_back(ele);
    swim(arr, arr.size() - 1);
}

void delMax(vector<int> &arr) {
    int n = arr.size();
    if (n == 0 || n == 1)
        return;
    swap(arr[0], arr[n - 1]);
    arr.pop_back();
    sink(arr, 0, arr.size() - 1);
}

void heapSort(vector<int> &arr) {
    heapfully(arr);
    int n = arr.size();
    if (n == 1 && n == 0)
        return;
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        sink(arr, 0, i - 1);
    }
}

void print(const vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}