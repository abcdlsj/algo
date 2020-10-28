#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                if (!dfs(graph, color, i, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int idx, int c) {
        color[idx] = c;
        for (auto &e : graph[idx]) {
            if (color[e] == c)
                return false;
            else if (color[e] == 0 && !dfs(graph, color, e, -c))
                return false;
        }
        return true;
    }
};

int main() {}