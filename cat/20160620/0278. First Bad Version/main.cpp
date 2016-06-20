#include <stdio.h>
#include "solution.hpp"

int badVersion;

bool isBadVersion(int version) {
  return version >= badVersion;
}

int main() {
  Solution s;
  int n = 2126753390;
  badVersion = 1702766719;
  int v = s.firstBadVersion(n);
  printf("badVersion = %d, v = %d\n", badVersion, v);
  return 0;
}
