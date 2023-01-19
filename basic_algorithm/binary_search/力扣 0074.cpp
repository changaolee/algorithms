class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid / n][mid % n] >= target) r = mid;
            else l = mid + 1;
        }
        return matrix[r / n][r % n] == target;
    }
};