class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix.resize(matrix.size());

        for (int i = 0; i < matrix.size(); i++) {
            prefix[i].resize(matrix[i].size());
            int sum = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                sum += matrix[i][j];
                prefix[i][j] = sum;
                if (i != 0) {
                    prefix[i][j] += prefix[i - 1][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int minusLeft = 0;
        int minusTop = 0;

        if (col1 != 0) { // Calculate the left
            int minusAgain = 0;
            if (row1 != 0) {
                minusAgain = sumRegion(0, 0, row1 - 1, col1 - 1);
            }
            minusLeft = sumRegion(0, 0, row2, col1 - 1) - minusAgain;
        }

        if (row1 != 0) { // Calculate the top
            minusTop = sumRegion(0, 0, row1 - 1, col2);
        }

        int val = prefix[row2][col2];
        return val - minusLeft - minusTop;
    }

private:
    vector<vector<int>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */