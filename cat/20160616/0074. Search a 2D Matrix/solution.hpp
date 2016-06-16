class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if (row == 0) return false;
    int col = matrix[0].size();
    if (col == 0) return false;

    int sz = row * col;
    int f = 0;
    int t = sz;
    while (f < t) {
      int m = (f + t) / 2;
      int r = m / col;
      int c = m % col;
      if (matrix[r][c] == target) {
        return true;
      }
      if (matrix[r][c] < target) {
        f = m + 1;
      } else {
        t = m;
      }
    }

    return false;
  }
};
