#include <cstdint>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int f = 1, t = n;
    while (f < t) {
      int m = ((uint64_t)f + t)/2;
      if (isBadVersion(m)) {
        t = m;
      } else {
        f = m + 1;
      }
      // printf("m = %d, f = %d, t = %d\n", m, f, t);
    }
    return f;
  }
};
