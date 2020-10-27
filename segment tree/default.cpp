#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

vector<int> tree(MAX);
vector<int> nums = {1, 3, 5, 7, 9, 11};

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = nums[start];
    } else {
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        build(left_node, start, mid);
        build(right_node, mid + 1, end);

        tree[node] = tree[left_node] + tree[right_node];
	}
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        nums[idx] = val;
        tree[node] = val;
    }
    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    if (idx >= start && idx <= mid) {
        update(left_node, start, mid, idx, val);
    } else {
        update(right_node, mid + 1, end, idx, val);
    }

    tree[node] = tree[left_node] + tree[right_node];
}

int main() {
    int size = 6;
    build(0, 0, size - 1);
    for (int i = 0; i < 15; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    update(0, 0, size - 1, 4, 6);
    for (int i = 0; i < 15; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
}
