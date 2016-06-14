#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {

    int total = nums.size();

    std::unordered_map<int, int> value_index;
    std::vector<int> parents(total);
    std::vector<int> setsize(total);

    for (int i = 0; i < total; i++) {
      int curr = nums[i];

      parents[i] = i;

      if (value_index.find(curr) == value_index.end()) {
        setsize[i] = 1;
        value_index[nums[i]] = i;
      } else {
        setsize[i] = 0;
      }
    }

    int maxsize = 1;
    for (int i = 0; i < total; i++) {
      int curr = nums[i];
      int prev = curr - 1;
      int next = curr + 1;

      if (value_index.find(prev) != value_index.end()) {
        int prev_idx = value_index[prev];
   
        int curr_root = find_set(parents, i);
        int prev_root = find_set(parents, prev_idx);

        if (curr_root != prev_root) {
          setsize[prev_root] += setsize[curr_root];
          parents[curr_root] = prev_root;

          if (setsize[prev_root] > maxsize) {
            maxsize = setsize[prev_root];
          }
        }
      }

      if (value_index.find(next) != value_index.end()) {
        int next_idx = value_index[next];

        int curr_root = find_set(parents, i);
        int next_root = find_set(parents, next_idx);

        if (curr_root != next_root) {
          setsize[curr_root] += setsize[next_root];
          parents[next_root] = curr_root;

          if (setsize[curr_root] > maxsize) {
            maxsize = setsize[curr_root];
          }
        }
      }

      //

    }
    return maxsize;
  }

private:
  int find_set(std::vector<int>& parents, int idx) {
    if (idx < 0) {
      return idx;
    }
    if (parents[idx] == idx) {
      return idx;
    }
    int root_idx = find_set(parents, parents[idx]);
    parents[idx] = root_idx;
    return root_idx;
  }
};
