#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> G(N + 1);
        for (auto& e :  dislikes) {
            int a= e[0], b = e[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> color(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0) {
                if (!dfs(G, color, i, 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(const vector<vector<int>>& G, vector<int>& color, int idx, int t) {
        color[idx] = t;
        for (auto& e : G[idx]) {
            if (color[e] == t) return false;
            else if (color[e] == 0 && !dfs(G, color, e, -t)) return false;
        }
        return true;
    }
};

int main () {}