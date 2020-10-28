#include <bits/stdc++.h>
using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x){};
};

class Solution {
  public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode *> topSort(vector<DirectedGraphNode *> &graph) {
        // write your code here
        int n = graph.size();
        vector<DirectedGraphNode *> ret;
        unordered_map<DirectedGraphNode *, int> indegree;

        for (auto &node : graph) {
            for (auto &e : node->neighbors) {
                indegree[e]++;
            }
        }
        queue<DirectedGraphNode *> que;
        for (auto &node : graph) {
            if (indegree[node] == 0) {
                que.push(node);
            }
        }

        while (!que.empty()) {
            DirectedGraphNode *cur = que.front();
            que.pop();
            ret.push_back(cur);
            for (auto &e : cur->neighbors) {
                indegree[e]--;
                if (indegree[e] == 0) {
                    que.push(e);
                }
            }
        }

        return ret;
    }
};
