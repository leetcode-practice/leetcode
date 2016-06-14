#include <vector>

#include "solution.hpp"

void print_vector(const char* msg, const std::vector<int>& v) {
  printf("%s: ", msg);
  for (int i=0;i<v.size();i++){
    printf("%d%c", v[i], (i==v.size()-1?'\n':','));
  }
}

int main() {
  Solution s;

  std::vector<int> t1 = {1,2,3,4,5,6,7};
  s.rotate(t1, -10);
  print_vector("rotate 3", t1);

  return 0;
}
