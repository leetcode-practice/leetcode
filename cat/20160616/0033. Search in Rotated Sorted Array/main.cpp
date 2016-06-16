#include <vector>
using namespace std;

#include "solution.hpp"

int main() {
  Solution s;
  vector<int> arr = {4,5,6,7,0,1,2};
  int target = 0;
  int idx = s.search(arr, target);
  printf("idx = %d\n", idx);
  return 0;
}
