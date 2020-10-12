#include "../../utils/print.h"
#include <bits/stdc++.h>
using namespace std;

// reverse_stack 取出一个数字 val，直到只有最后一个数字
// 这个时候，我们有一个数字在手中 val，”一个数字“在栈中
// put 就是取出栈中的”一个数字“，先把我们的放进去，然后再放取出的“一个数字”
void put(stack<int> &stk, int val) {
    if (stk.size() == 0) {
        stk.push(val);
        return;
    }
    int tp = stk.top();
    stk.pop();
    put(stk, val);
    stk.push(tp);
}
void reverse_stack(stack<int> &stk) {
    if (stk.size() == 1) {
        return;
    }

    int tp = stk.top();
    stk.pop();
    reverse_stack(stk);
    put(stk, tp);
}

int main() {
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    print_stack(stk);
    reverse_stack(stk);
    print_stack(stk);
    return 0;
}
