#include <iostream>
#include <vector>

int partation(std::vector<int> &arr, int begin, int end) {
    int cpr = arr[end], le = begin, ri = end - 1;
    while (le < ri) {
        while (le < ri && arr[le] < cpr) le++;
        while (le < ri && arr[ri] >= cpr) ri--;
        std::swap(arr[le], arr[ri]);
    }
    if (arr[le] >= cpr) {
        std::swap(arr[le], arr[end]);
    } else {
        le++;
    }

    return le;
}

void quickSort1Helper(std::vector<int> &arr, int begin, int end, int k) {
    if (begin >= end) return;
    int par = partation(arr, begin, end);
    quickSort1Helper(arr, begin, par - 1, k);
    if (par > k) {
        return ;
    } else {
        quickSort1Helper(arr, par + 1, end, k);
    }
}

void quickSort1(std::vector<int> &arr, int k) {
    quickSort1Helper(arr, 0, arr.size() - 1, k);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    quickSort1(arr, k - 1);
    std::cout << arr[k - 1];
}