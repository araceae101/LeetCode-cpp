// use four prefix sum

// Problem: https://leetcode.com/problems/largest-magic-square/
// Discussion: https://leetcode.com/problems/largest-magic-square/discuss/1267447/C++-Prefix-Sum-solution-(best-time-20ms-beats-100)

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp_row(m, vector<int>(n, 0));
        vector<vector<int>> dp_col(m, vector<int>(n, 0));
        vector<vector<int>> dp_di1(m, vector<int>(n, 0));
        vector<vector<int>> dp_di2(m, vector<int>(n, 0));
        
        // dp for row
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dp_row[i][j] = (j == 0 ? 0 : dp_row[i][j-1]) + grid[i][j];
        // dp for column
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dp_col[i][j] = (i == 0 ? 0 : dp_col[i-1][j]) + grid[i][j];
        // dp for diagonal (left to right)
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dp_di1[i][j] = (i==0||j==0 ? 0 : dp_di1[i-1][j-1]) + grid[i][j];
        // dp for diagonal (right to left)
        for (int i = 0; i < m; ++i) for (int j = n-1;j>=0; --j) dp_di2[i][j] = (i==0||j==n-1 ? 0:dp_di2[i-1][j+1]) + grid[i][j];
        
        
        for (int k = min(m, n); k > 1; --k) {
            for (int i = 0; i + k - 1 < m; ++i) {
                int start_row = i, end_row = i + k - 1;
                for (int j = 0; j + k - 1 < n; ++j) {
                    
                    int start_col = j, end_col = j + k - 1;
                    
                    // check diagonal
                    int first_di1 = dp_di1[end_row][end_col] -(start_row==0||start_col==0?0: dp_di1[start_row-1][start_col-1]);
                    int first_di2 = dp_di2[end_row][start_col] -(start_row==0||end_col==n-1?0: dp_di2[start_row-1][end_col+1]);
                    
                    if (first_di1 != first_di2) continue;
                    
                    // check row and col
                    int row_0 = dp_row[start_row][end_col] - (start_col == 0 ? 0 : dp_row[start_row][start_col-1]);
                    int col_0 = dp_col[end_row][start_col] - (start_row == 0 ? 0 : dp_col[start_row-1][start_col]);
                    
                    if (row_0 != col_0 || row_0 != first_di1 || col_0 != first_di2) continue;
                    
                    int z = 1;
                    for (; z < k; ++z) {
                        int row_k = dp_row[start_row + z][end_col] - (start_col == 0 ? 0 : dp_row[start_row + z][start_col-1]);
                        int col_k = dp_col[end_row][start_col + z] - (start_row == 0 ? 0 : dp_col[start_row-1][start_col + z]);
                        if (row_0 != row_k || col_0 != col_k) break;
                    }
                    if (z == k) return k;
                }
            }
        }
        return 1;
    }
};