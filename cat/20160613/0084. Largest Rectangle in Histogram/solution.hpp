#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    std::vector<int> count;
    int total = heights.size();
    int stack_size = 0;
    int max_area = 0;
    for (int i = 0; i < total; i++) {
      if (stack_size == 0 || heights[i] > heights[stack_size-1]) {
        heights[stack_size] = heights[i];
        stack_size++;
        count.push_back(1);
      } else if (heights[i] == heights[stack_size-1]) {
        count[stack_size-1]++;
      } else {
        // pops
        int curr_max = popArea(heights, stack_size, count, heights[i], true);
        max_area = (curr_max > max_area ? curr_max : max_area);
      }
    }
    //
    int curr_max = popArea(heights, stack_size, count, 0, false);
    max_area = (curr_max > max_area ? curr_max : max_area);
    return max_area;
  }

private:
  int popArea(vector<int> &heights, int &stack_size, std::vector<int> &count, int val, bool push) {
    if (enable_debug) {
      debug("before_pop", heights, stack_size, count);
    }
    //
    int next_size = stack_size;
    int max_area = 0;
    int acc_count = 0;
    while (next_size > 0) {
      int next_val = heights[next_size-1];
      if (next_val < val) {
        break;
      }

      acc_count += count[next_size-1];
      int area = next_val * acc_count;
      if (enable_debug) {
        printf("  area = %d, next_val = %d, acc_count = %d\n", area, next_val, acc_count);
      }
      if (area > max_area) {
        max_area = area;
      }
      next_size--;
      count.pop_back();
    }
    stack_size = next_size;
    if (push) {
      // push
      heights[stack_size++] = val;
      count.push_back(acc_count+1);
    }
    //
    if (enable_debug) {
      debug("after_pop", heights, stack_size, count);
    }
    return max_area;
  }

  bool enable_debug = false;

  void debug(const char* msg, const std::vector<int> &heights, int stack_size, const std::vector<int> &count) {
    printf(">> BEGIN: %s\n", msg);
    printf(" stack_size = %d\n", stack_size);
    printf(" heights = ");
    for (int i=0;i<heights.size();i++) {
      printf("%d%c", heights[i], (i == heights.size()-1 ? '\n' : ','));
    }
    printf(" count = ");
    for (int i=0;i<count.size(); i++) {
      printf("%d%c", count[i], (i == count.size()-1 ? '\n' : ','));
    }
    printf(">> END\n\n");
  }
};
