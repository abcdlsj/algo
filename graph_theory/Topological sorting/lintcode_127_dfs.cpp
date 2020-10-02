#include <bits/stdc++.h>
using namespace std;

struct DirectedGraphNode {
  int label;
  vector<DirectedGraphNode*> neighbors;
  DirectedGraphNode(int x) : label(x){};
};

class Solution {
public:
  /*
   * @param graph: A list of Directed graph node
   * @return: Any topological order for the given graph.
   */
  vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode *> &graph) {
    // write your code here
	unordered_map<DirectedGraphNode*, int> vis;
	stack<DirectedGraphNode*> stk;

	for (auto& e : graph) {
	  if (vis.find(e) == vis.end()) {
		dfs(graph, vis, e, stk);
	  }
	}

	vector<DirectedGraphNode*> ret;
	while (!stk.empty()) {
	  ret.push_back(stk.top());
	  stk.pop();
	}

	return ret;
  }

  void dfs(vector<DirectedGraphNode*> &graph, unordered_map<DirectedGraphNode*, int>& vis, DirectedGraphNode* node, stack<DirectedGraphNode*> stk) {
	vis[node] = 1;

	for (auto& e : node->neighbors) {
	  if (vis.find(e) == vis.end()) {
		dfs(graph, vis, e, stk);
	  }
	}

	stk.push(node);
  }
};

int main () {

}
