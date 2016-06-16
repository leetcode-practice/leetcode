#include "solution.hpp"

int main() {
  Solution s;

  vector<vector<int>> grid = {
    {2, 2, 1, 3},
    {2, 1, 8, 9},
    {9, 9, 1, 2},
    {10, 1, 3, 4}
  };
  int v = s.minPathSum(grid);
  printf("v = %d\n", v);

  return 0;
}
