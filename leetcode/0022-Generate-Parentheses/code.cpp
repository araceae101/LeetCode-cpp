// Problem: https://leetcode.com/problems/generate-parentheses/
// Method: DFS
// Discussion: https://leetcode.com/problems/generate-parentheses/discuss/1277846/C++-recursive-solution-or-time-O(2n)-or-space-O(N)

class Solution {
    void generate(int l, int r, string tmp, vector<string>& res) {
        if (l == 0 && r == 0) {
            res.push_back(tmp);
            return;
        }
        if (l > 0)  generate(l-1, r, tmp+'(', res);
        if (r > 0 && r > l) generate(l, r-1, tmp+')', res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }
};