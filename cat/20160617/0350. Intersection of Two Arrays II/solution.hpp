#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> n1;
    for (int i = 0; i < nums1.size(); i++) {
      n1[nums1[i]]++;
    }
    vector<int> res;
    for (int i = 0; i < nums2.size(); i++) {
      int v = nums2[i];
      if (n1.find(v) == n1.end()) {
        continue;
      }
      int cnt = n1[v];
      if (cnt > 0) {
        res.push_back(v);
        n1[v] = cnt - 1;
      }
    }
    return res;
  }
};
