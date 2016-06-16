class Solution {
public:
  int search(vector<int>& nums, int target) {
    int sz = nums.size();
    if (sz == 0) {
      return -1;
    }
    int offset = 0;
    for (; offset < sz; offset++) {
      int prev = (offset - 1 + sz) % sz;
      if (nums[prev] > nums[offset]) {
        break;
      }
    }

    //
    int f = 0;
    int t = sz;
    while (f < t) {
      int m = (f + t) / 2;
      int i = (m + offset) % sz;
      int curr = nums[i];
      //printf("m = %d, i = %d, f = %d, t = %d, curr = %d, offset = %d\n", m, i, f, t, curr, offset);
      if (curr == target) {
        return i;
      }
      if (curr < target) {
        f = m + 1;
      } else {
        t = m;
      }
    }

    return -1;
  }
};
