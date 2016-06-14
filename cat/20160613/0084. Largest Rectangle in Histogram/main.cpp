#include "solution.hpp"

int main() {
  Solution s;

  //std::vector<int> t1 {2,1,5,6,2,3};
  //std::vector<int> t1 {1,2,6,1,4,8};
  //std::vector<int> t1 {2, 1, 2};
  //std::vector<int> t1 {2,4,34,3,6,26,3,5,45,2,534,5,34,53,32};
  std::vector<int> t1 {};
  int r1 = s.largestRectangleArea(t1);
  printf("r = %d\n", r1);
  return 0;
}
