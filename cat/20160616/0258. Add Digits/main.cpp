#include <stdio.h>

#include "solution.hpp"

int main() {
  Solution s;
  for (int i = 0; i < 200; i++) {
    int v = s.addDigits(i);
    printf("%d%c", v, (i%10==9?'\n':','));
  }
  return 0;
}
