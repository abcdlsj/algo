#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);

        for (auto& e : prerequisites) {
            edges[e[0]].push_back(e[1]);
        }
        vector<int> vis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(edges, vis, i)) {
                return false;
            }
        }

        return true;
    }

    // vis[i] == -1 // 代表之前的 dfs 判断过，走这个点的 dfs 不会出现环
    // vis[i] == 1 // 代表当前 dfs 访问过这个点，出现环
    bool dfs(const vector<vector<int>>& edges, vector<int>& vis, int i) {
        if (vis[i] == -1) return true;
        if (vis[i] == 1) return false;
        vis[i] = 1;
        for (auto& e : edges[i]) {
            if (!dfs(edges, vis, e)) {
                return false;
            }
        }

        vis[i] = -1;
        return true;
    }
};

int main() {}
