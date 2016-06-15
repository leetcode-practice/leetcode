#include <vector>

#include "solution.hpp"

int main() {
  Solution s;

  // vector<vector<int>> m = {
  //   {9,9,4},
  //   {6,6,8},
  //   {2,1,1}
  // };
  vector<vector<int>> m = {
    {3,4,5},
    {3,2,6},
    {2,2,1}
  };
  int v;
  v = s.longestIncreasingPath(m);
  printf("v = %d\n", v);


  return 0;
}

