/*
* Problem: https://leetcode.com/problems/minimum-knight-moves/
* My Discussion: 
*/

class Solution {
    vector<int> dir{2, 1, -2, -1, 2, -1, -2, 1, 2};
public:
    int minKnightMoves(int x, int y) {
        queue<pair<int, int>> q;
        unordered_map<int, unordered_map<int, bool>> visit;
        q.push({0, 0});
        visit[0][0] = true;
        int res = 0;
        x = abs(x); y = abs(y);
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto [a, b] = q.front(); q.pop();
                if (a == x && b == y)   return res;
                for (int j = 0; j < dir.size()-1; ++j) {
                    int next_a = abs(a + dir[j]);
                    int next_b = abs(b + dir[j+1]);
                    if (!visit[next_a][next_b]) {
                        q.push({next_a, next_b});
                        visit[next_a][next_b] = true;
                    }
                }
            }
            ++res;
        }
        return res;
    }
};