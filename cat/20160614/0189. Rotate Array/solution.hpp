#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) {
      return;
    }
    int offset = ((k % n) + n) % n;
    if (offset == 0) {
      return;
    }
    reverse(nums, 0, n-1);
    reverse(nums, 0, offset-1);
    reverse(nums, offset, n-1);
  }

private:
  void reverse(vector<int>& nums, int f, int t) {
    while (f < t) {
      int v = nums[t];
      nums[t] = nums[f];
      nums[f] = v;
      f++;
      t--;
    }
  }
};
