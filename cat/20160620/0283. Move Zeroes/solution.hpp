#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int w = 0, r = 0;
    int sz = nums.size();
    while (r < sz) {
      if (nums[r] == 0) {
        ++r;
      } else {
        if (w != r) {
          swap(nums[w], nums[r]);
        }
        ++w;
        ++r;
      }
    }
  }
};
