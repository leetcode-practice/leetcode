#include <vector>
using namespace std;

#include "solution.hpp"

int main() {
  Solution s;
  vector<vector<int>>  mat = {
    {1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  bool ret = s.searchMatrix(mat, 12);
  printf("result = %d\n", (ret ? 1 : 0));
  return 0;
}
