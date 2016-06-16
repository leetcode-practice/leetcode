/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {
      return result;
    }

    traversal(root, 0, result);
    return result;
  }

private:
  void traversal(TreeNode *root, int depth, vector<int>& result) {
    if (root == NULL) {
      return;
    }
    if (depth >= result.size()) {
      result.push_back(root->val);
    } else {
      result[depth] = root->val;
    }
    if (root->left != NULL) {
      traversal(root->left, depth+1, result);
    }
    if (root->right != NULL) {
      traversal(root->right, depth+1, result);
    }
  }
};
