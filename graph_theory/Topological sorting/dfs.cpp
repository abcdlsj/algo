#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> cnt;
    vector<vector<int>> adj;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        cnt.resize(numCourses, -1);
        adj.resize(numCourses);

        for (auto& e : prerequisites) adj[e[1]].push_back(e[0]);
        for (int i = 0; i < numCourses; i++) {
            if (cnt[i] == -1) {
                if (!dfs())
            }
        }
    }
    bool dfs(int u) {
        cnt[u] = -1;
        for (auto v : adj[u]) {
            if (cnt[v] < 0) {
                return false;
            } else if ()
        }
    }
};