#include <vector>
#include <cstdint>

using namespace std;

/**
 *  C(n, m+1) = C(n,m) * (n-m)/(m+1)
 */
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    std::vector<int> res(rowIndex + 1);
    res[0] = 1;
    int n = rowIndex;
    for (int m = 0; m < rowIndex; m++) {
      res[m+1] = (uint64_t)res[m] * (n - m) / (m + 1);
    }
    return res;
  }
};
