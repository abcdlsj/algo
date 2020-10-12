#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void print_arr(vector<int> arr) {
    for (auto &e : arr) {
        cout << e << " ";
    }
    cout << "\n";
}
void print_vec(vector<vector<int>> vecs) {
    for (int i = 0; i < vecs.size(); i++) {
        for (int j = 0; j < vecs[i].size(); j++) {
            cout << vecs[i][j] << " ";
        }
        cout << "\n";
    }
}

void print_stack(stack<int> stk) {
    stack<int> st(stk);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}
