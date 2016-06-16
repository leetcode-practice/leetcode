#include <stdio.h>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include "solution.hpp"

int main() {
  Solution s;
  s.postorderTraversal(NULL);
  return 0;
}
