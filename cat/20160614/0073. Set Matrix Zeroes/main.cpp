#include <vector>
#include <stdio.h>

#include "solution.hpp"

void print_mat(const char* msg, const vector<vector<int>>& m) {
  printf("%s\n", msg);
  for (int r = 0; r < m.size(); r++) {
    const vector<int> &row = m[r];
    for (int c = 0; c < row.size(); c++) {
      printf("%d%c", row[c], (c == row.size()-1 ? '\n' : ','));
    }
  }
  printf("\n");
}

int main() {
  Solution s;
  vector<vector<int>> m = {
    {0,0,0,5},
    {4,3,1,4},
    {0,1,1,4},
    {1,2,1,3},
    {0,0,1,1}
  };

  // vector<vector<int>> m = {
  //   {1,1,1},
  //   {0,1,2}
  // };

  s.setZeroes(m);
  print_mat("", m);
  return 0;
}
