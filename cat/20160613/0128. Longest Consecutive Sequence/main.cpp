#include <stdio.h>
#include "solution.hpp"

int main() {
  Solution s;
  //int t1[] = {5, 100, 1, 2, 3, 2, 4, 8, 7};
  int t1[] = {0};
  int sz = sizeof(t1)/sizeof(t1[0]);
  std::vector<int> nums(t1, t1 + sz);
  int v = s.longestConsecutive(nums);
  printf("v = %d\n", v);
  return 0;
}
