class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> preCal(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preCal[i][j] = mat[i - 1][j - 1]
                             + preCal[i - 1][j]
                             + preCal[i][j - 1]
                             - preCal[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int rb = max(0, i - k);
                int cb = max(0, j - k);

                int rf = min(m - 1, i + k);
                int cf = min(n - 1, j + k);

                mat[i][j] = preCal[rf + 1][cf + 1]
                          - preCal[rb][cf + 1]
                          - preCal[rf + 1][cb]
                          + preCal[rb][cb];
            }
        }

        return mat;
    }
};
