class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLow = 0;
        int rowHigh = matrix.size() - 1;

        int idx = -1;
        while (rowLow <= rowHigh) {
            int midRow = (rowLow + rowHigh) / 2;

            int firstCol = matrix[midRow][0];
            int endCol = matrix[midRow][matrix[midRow].size() - 1];

            if (target < firstCol) {
                rowHigh = midRow - 1;
            } else if (target > endCol) {
                rowLow = midRow + 1;
            } else {
                idx = midRow;
                break;
            }
        }

        if (idx == -1) {
            return false;
        }

        int low = 0;
        int high = matrix[idx].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (matrix[idx][mid] < target) {
                low = mid + 1;
            } else if (matrix[idx][mid] > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
