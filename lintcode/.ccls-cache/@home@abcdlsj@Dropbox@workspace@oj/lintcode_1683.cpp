#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param n: 
     * @param v: 
     * @return: nothing
     */
    int killMonster(int n, vector<vector<int>> &v) {
        vector<int> otto = v[0];
        queue<vector<int>> que;
        int ans = 0;
        for (int i = 1; i < v.size(); i++) que.push(v[i]);
        while (true) {
            bool isout = true;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                vector<int> tmp = que.front(); que.pop();
                bool iseat = true; 
                for (int j = 0; j < 5; j++) {
                    if (otto[j] < tmp[j]) {
                        que.push(tmp);
                        iseat = false;
                        break;
                    }
                }
                
                if (iseat) {
                    isout = false;
                    ans++;
                }
            }
            
            if (isout) break;
        }
        
        return ans;
    }
};

int main () {
  Solution solution;
  int n = 5;
  vector<vector<int>> v = {{3,9,2,1,5},{0,9,6,5,9},{6,1,8,6,3},{3,9,1,1,4},{9,9,0,6,5},{5,6,5,6,7}};
  cout << solution.killMonster(n, v) << endl;
}