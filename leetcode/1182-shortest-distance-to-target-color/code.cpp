// Problem: https://leetcode.com/problems/shortest-distance-to-target-color/
// Method: prefix & suffix
// Discussion: https://leetcode.com/problems/shortest-distance-to-target-color/discuss/1274658/C++-prefix-and-suffix-or-time-O(N)-or-space-O(N)

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> c(3, vector<int>(n, -1));
        for (int i = 0, j = n-1; i < n && j >= 0; ++i, --j) {
            c[colors[i]-1][i] = 0;
            if (i > 0) {
                if (c[0][i-1] != -1) c[0][i] = c[0][i] == -1 ? c[0][i-1]+1 : min(c[0][i], c[0][i-1]+1);
                if (c[1][i-1] != -1) c[1][i] = c[1][i] == -1 ? c[1][i-1]+1 : min(c[1][i], c[1][i-1]+1);
                if (c[2][i-1] != -1) c[2][i] = c[2][i] == -1 ? c[2][i-1]+1 : min(c[2][i], c[2][i-1]+1);
            }
            c[colors[j]-1][j] = 0
            if (j < n-1) {
                if (c[0][j+1] != -1) c[0][j] = c[0][j] == -1 ? c[0][j+1]+1 : min(c[0][j], c[0][j+1]+1);
                if (c[1][j+1] != -1) c[1][j] = c[1][j] == -1 ? c[1][j+1]+1 : min(c[1][j], c[1][j+1]+1);
                if (c[2][j+1] != -1) c[2][j] = c[2][j] == -1 ? c[2][j+1]+1 : min(c[2][j], c[2][j+1]+1);
            }
        }
        
        vector<int> res;
        for (auto &q : queries)
            res.push_back(c[q[1]-1][q[0]]);
        return res;
    }
};