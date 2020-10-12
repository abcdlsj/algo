#include <bits/stdc++.h>
using namespace std;

// 207. 课程表
// https://leetcode-cn.com/problems/course-schedule/
// 测试通过
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> edges(numCourses);

        for (auto& e : prerequisites) {
            indegree[e[0]]++;
            edges[e[1]].push_back(e[0]);
        }
        int count = 0;
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) que.push(i);
        while (!que.empty()) {
            count++;
            int cur = que.front();
            que.pop();
            for (auto& e : edges[cur]) {
                indegree[e]--;
                if (indegree[e] == 0) {
                    que.push(e);
                }
            }
        }
        return count == numCourses;
    }
};

int main() {}