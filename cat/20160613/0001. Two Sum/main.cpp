#include "solution.hpp"
#include <vector>

using namespace std;

void print_result(const std::vector<int>& v) {
  for (int i=0; i< v.size(); i++) {
    printf("%d, ", v[i]);
  }
  printf("\n");
}

int main() {
  Solution s;
  int t1_arr[] = {2, 7, 11, 15};
  std::vector<int> t1(t1_arr, t1_arr + 4);
  std::vector<int> r1 = s.twoSum(t1, 9);
  print_result(r1);
  return 0;
}
