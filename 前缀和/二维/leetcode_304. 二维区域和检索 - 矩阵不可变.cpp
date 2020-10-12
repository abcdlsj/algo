class NumMatrix {
  public:
    vector<vector<int>> ma;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            matrix[i][0] += matrix[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            matrix[0][j] += matrix[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] +=
                    matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
        ma = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // v1 v2
        // v3 v4
        // ma[row2][col2] - ma[row1 - 1][col2] - ma[row2][col1 - 1] + ma[row1 -
        // 1][col1 - 1];
        int v1 = (col1 < 1 || row1 < 1) ? 0 : ma[row1 - 1][col1 - 1];
        int v2 = (row1 < 1) ? 0 : ma[row1 - 1][col2];
        int v3 = (col1 < 1) ? 0 : ma[row2][col1 - 1];
        int v4 = ma[row2][col2];
        return v4 - v2 - v3 + v1;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */