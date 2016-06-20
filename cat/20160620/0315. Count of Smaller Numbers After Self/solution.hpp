#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int>& r, const char *msg = "") {
  printf("%s", msg);
  for (int i=0;i<r.size();i++) {
    printf("%d%c", r[i], (i==r.size()-1 ? '\n':','));
  }
}

struct comparator {
  vector<int>& nums;
  comparator(vector<int>& n) : nums(n) {}
  bool operator()(int i, int j) {
    return nums[i] < nums[j];
  }
};

class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> idx(nums.size());
    for (int i = 0; i < idx.size(); i++) {
      idx[i] = i;
    }
    // sort idx by nums
    sort(idx.begin(), idx.end(), comparator(nums));
    // print_vector(idx, "sorted idx = ");
    // reassign nums
    int val = 1;
    vector<int> values(nums.size());
    for (int i = 0; i < idx.size(); i++) {
      int curr = idx[i];
      if (i > 0 && nums[idx[i-1]] == nums[idx[i]]) {
        values[idx[i]] = values[idx[i-1]];
      } else {
        values[idx[i]] = val++;
      }
    }
    // print_vector(values, "values = ");
    // calc
    vector<int> res(values.size());
    idx.resize(val);    
    fill(idx.begin(), idx.end(), 0);
    for (int i = values.size()-1; i >= 0; i--) {
      addValue(idx, values[i], 1);
      res[i] = getSum(idx, values[i] - 1);
      // print_vector(idx, "sums = ");
    }
    return res;
  }

private:
  void addValue(vector<int>& sums, int idx, int delta) {
    while (idx < sums.size()) {
      sums[idx] += delta;
      idx += (idx & (-idx));
    }
  }

  int getSum(vector<int>& sums, int idx) {
    if (idx <= 0) {
      return 0;
    }
    int val = 0;
    while (idx > 0) {
      val += sums[idx];
      idx -= (idx & (-idx));
    }
    return val;
  }
};
