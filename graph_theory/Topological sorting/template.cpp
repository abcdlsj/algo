#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> indegree;
vector<int> ans;

void topological_sort() {
  queue<int> que;
  int n = edges.size();
  for (int i = 0; i < n; i++) {
	if (indegree[i] == 0) {
	  que.push(i);
	}
  }
  while (!que.empty()) {
	auto cur = que.front(); que.pop();
	ans.push_back(cur);

	for (auto& e : edges[cur]) {
	  indegree[e]--;
	  if (indegree[e] == 0) {
		que.push(e);
	  }
	}
  }

}

int main () {
}
