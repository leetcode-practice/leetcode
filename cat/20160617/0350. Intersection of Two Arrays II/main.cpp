#include <stdio.h>
#include "solution.hpp"

int main() {
  Solution s;
  vector<int> nums1 = {1, 2, 2, 3};
  vector<int> nums2 = {2, 5, 2, 2};
  vector<int> res = s.intersect(nums1, nums2);

  for (int i=0;i<res.size();i++) {
    printf("%d%c", res[i], (i==res.size()-1?'\n':','));
  }

  return 0;
}
