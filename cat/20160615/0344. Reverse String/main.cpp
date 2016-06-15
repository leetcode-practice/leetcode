#include <stdio.h>
#include "solution.hpp"

int main() {
  Solution s;

  printf("%s\n", s.reverseString("hello").c_str());
  return 0;
}
