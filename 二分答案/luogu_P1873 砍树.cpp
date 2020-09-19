#include <bits/stdc++.h>
using namespace std;

/*
题目描述
伐木工人米尔科需要砍倒M米长的木材。这是一个对米尔科来说很容易的工作，因为他有一个漂亮的新伐木机，可以像野火一样砍倒森林。不过，米尔科只被允许砍倒单行树木。

米尔科的伐木机工作过程如下：米尔科设置一个高度参数H（米），伐木机升起一个巨大的锯片到高度H，并锯掉所有的树比H高的部分（当然，树木不高于H米的部分保持不变）。米尔科就行到树木被锯下的部分。

例如，如果一行树的高度分别为20，15，10和17，米尔科把锯片升到15米的高度，切割后树木剩下的高度将是15，15，10和15，而米尔科将从第1棵树得到5米，从第4棵树得到2米，共得到7米木材。

米尔科非常关注生态保护，所以他不会砍掉过多的木材。这正是他为什么尽可能高地设定伐木机锯片的原因。帮助米尔科找到伐木机锯片的最大的整数高度H，使得他能得到木材至少为M米。换句话说，如果再升高1米，则他将得不到M米木材。

输入格式
第1行：2个整数N和M，N表示树木的数量（1<=N<=1000000）,M表示需要的木材总长度（1<=M<=2000000000）

第2行：N个整数表示每棵树的高度，值均不超过1000000000。所有木材长度之和大于M，因此必有解。

输出格式
第1行：1个整数，表示砍树的最高高度。
*/

bool check(vector<int>& heights, int h, int target) {
    int sum = 0;

    for (int i = 0; i < heights.size(); i++) {
        sum += (heights[i] > h ? heights[i] - h : 0);
        if (sum >= target) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int M, N;
    while (cin >> N >> M) {
        vector<int> heights(N);
        for (int i = 0; i < N; i++) cin >> heights[i];

        int le = 0, ri = *max_element(heights.begin(), heights.end());
        while (le < ri) {
            int mid = le + (ri - le + 1) / 2;
            if (check(heights, mid, M)) {
                le = mid;
            } else {
                ri = mid - 1;
            }
        }

        cout << le << endl;
    }
}