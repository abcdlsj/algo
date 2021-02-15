#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int start, int end) {
    int le = start, ri = end - 1, cpr = nums[end];
    while (le < ri) {
        while (le < ri && nums[le] < cpr) le++;
        while (le < ri && nums[ri] >= cpr) ri--;
        swap(nums[le], nums[ri]);
    }
    if (nums[le] >= cpr) swap(nums[le], nums[end]);
    else le++;
    return le;
}

void quick_sort(vector<int>& nums, int begin, int end) {
    if (begin >= end) return ;
    int par = partition(nums, begin, end);
    quick_sort(nums, begin, par - 1);
    quick_sort(nums, par + 1, end);
}

int main() {
    vector<int> nums{9, 8, 7, 6, 5, 4, 3, 2, 1};
    quick_sort(nums, 0, nums.size() - 1);
    for (auto& e : nums) cout << e << " "; cout << endl;
}

