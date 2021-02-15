#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums, int begin, int mid, int end) {
    int i = begin, j = mid + 1, idx = 0;
    vector<int> tmp(end - begin + 1);
    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) tmp[idx++] = nums[i++];
        else tmp[idx++] = nums[j++];
    }
    while (i <= mid) tmp[idx++] = nums[i++];
    while (j <= end) tmp[idx++] = nums[j++];
    for (i = begin, idx = 0; i <= end; i++, idx++) {
        nums[i] = tmp[idx];
    }
}

void merge_sort(vector<int>& nums, int begin, int end) {
    if (begin >= end) return ;
    int mid = begin + (end - begin) / 2;
    merge_sort(nums, begin, mid - 1);
    merge_sort(nums, mid + 1, end);
    merge(nums, begin, mid, end);
}

int main () {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(nums, 0, nums.size() - 1);
    for (auto& e : nums) cout << e << " "; cout << endl;
}