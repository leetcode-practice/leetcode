#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define map_t unordered_map
#define NODE_CAP 26

// TODO: suffix array
struct Node {
  char c;
  bool eos = false; // end of string
  //map_t<char, Node*> children;
  Node *children[NODE_CAP] = {};
};

class Solution {
public:
  vector<string> findWords(vector<vector<char>> &board, vector<string>& words) {
    row = board.size();
    if (row == 0) { return vector<string>(); }
    col = board[0].size();
    if (col == 0) { return vector<string>(); }

    flag.clear();
    flag.resize(row);
    for (int r = 0; r < row; r++) {
      flag[r].resize(col);
      fill(flag[r].begin(), flag[r].end(), false);
    }

    root = buildTree(words);

    result.clear();
    currstr.clear();
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        search(board, r, c);
      }
    }

    releaseTree(root);
    root = NULL;

    vector<string> unique_list;
    for (map_t<string,int>::iterator iter = result.begin(); iter != result.end(); iter++) {
      unique_list.push_back(iter->first);
    }

    return unique_list;
  }

private:

  int row, col;
  vector<vector<bool>> flag;
  Node *root;
  map_t<string, int> result;
  string currstr;

  void search(vector<vector<char>> &board, int r, int c) {

    static const int N = 4;
    static int DIR[][2] = {
      {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };

    flag[r][c] = true;
    currstr.push_back(board[r][c]);

    int ret = findString(root, currstr);
    if (ret > 0) {
      if (ret == 2) {
        result[currstr]++;
      }
      for (int i = 0; i < N; i++) {
        int rr = r + DIR[i][0];
        int cc = c + DIR[i][1];
        if (isOutOfRange(rr, cc)) {
          continue;
        }
        if (flag[rr][cc]) {
          continue;
        }
        search(board, rr, cc);
      }
    }

    currstr.pop_back();
    flag[r][c] = false;
  }

  bool isOutOfRange(int r, int c) {
    return r < 0 || r >= row || c < 0 || c >= col;
  }

  //////////////////////////////////////////////////////////////////

  Node * buildTree(vector<string>& words) {
    Node *root = new Node();
    for (int i=0;i<words.size(); i++) {
      addString(root, words[i]);
    }
    return root;
  }

  void releaseTree(Node *root) {
    // for (map_t<char, Node*>::iterator iter = root->children.begin(); iter != root->children.end(); iter++) {
    //   Node *curr = iter->second;
    for (int i = 0; i < NODE_CAP; i++) {
      Node *curr = root->children[i];
      if (curr != NULL) {
        releaseTree(curr);
      }
      root->children[i] = NULL;
    }
    //root->children.clear();
    delete root;
  }

  void addString(Node *root, const string& str) {
    for (int i = 0; i < str.size(); i++) {
      char c = str[i];
      Node *curr;
      if (root->children[c - 'a'] == NULL) {
      // if (root->children.find(c) == root->children.end()) {
        curr = new Node();
        curr->c = c;
      } else {
        curr = root->children[c - 'a'];
      }
      if (i == str.size() - 1) {
        curr->eos = true;
      }
      root->children[c - 'a'] = curr;
      root = curr;
    }
  }

  // 0: not found, 1: prefix, 2: full string
  int findString(Node * root, const string& str) {
    for (int i = 0; i < str.size(); i++) {
      char c = str[i];
      //if (root->children.find(c) == root->children.end()) {
      if (root->children[c - 'a'] == NULL) {
        return 0;
      }
      Node *curr = root->children[c - 'a'];
      root = curr;
    }
    return (root->eos ? 2 : 1); 
  }
};
