#include <vector>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    row = grid.size();
    if (row == 0) return 0;
    col = grid[0].size();
    if (col == 0) return 0;

    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        int left_value = getGridValue(grid, r, c-1);
        int up_value = getGridValue(grid, r-1, c);
        int curr_value = -1;
        if (left_value >= 0 && (curr_value < 0 || left_value < curr_value)) {
          curr_value = left_value;
        }
        if (up_value >= 0 && (curr_value < 0 || up_value < curr_value)) {
          curr_value = up_value;
        }
        if (curr_value >= 0) {
          grid[r][c] += curr_value;
        }
      }
    }
    return grid[row-1][col-1];
  }

private:
  int row;
  int col;

  int getGridValue(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= row || c < 0 || c >= col) {
      return -1;
    }
    return grid[r][c];
  }
};
