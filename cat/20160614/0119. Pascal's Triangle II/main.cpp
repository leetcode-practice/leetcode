#include <stdio.h>
#include <vector>
#include "solution.hpp"

int main() {
  Solution s;
  for (int k = 0; k <= 30; k++) {
    std::vector<int> v = s.getRow(k);

    printf("k = %d, row = ", k);
    for (int i=0;i<v.size();i++) {
      printf("%d%c", v[i], (i == v.size()-1 ? '\n' : ','));
    }
  }
  return 0;
}
