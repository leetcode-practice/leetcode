#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> indices;
    for (int i=0; i< nums.size(); i++) {
      indices[nums[i]] = i;
    }
    for (int i=0; i<nums.size(); i++) {
      int curr = nums[i];
      int remain = target - curr;
      if (indices.find(remain) != indices.end()) {
        int next = indices[remain];
        if (next == i) {
          continue;
        }
        vector<int> result;
        result.push_back(i);
        result.push_back(next);
        return result;
      }
    }
    return std::vector<int>();
  }
};
