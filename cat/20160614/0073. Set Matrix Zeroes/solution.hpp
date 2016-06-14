#include <vector>
using namespace std;


class Solution {
public:
  void setZeroes(vector<vector<int>>& m) {
    if (m.size() == 0 || m[0].size() == 0) {
      return;
    }
    int r0 = 1;
    int c0 = 1;
    int row = m.size();
    int col = m[0].size();
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (m[r][c] == 0) {
          if (r != 0) {
            m[r][0] = 0;
          } else {
            c0 = 0;
          }
          if (c != 0) {
            m[0][c] = 0;
          } else {
            r0 = 0;
          }
        }
      }
    }

    for (int r = 1; r < row; r++) {
      if (m[r][0] == 0) {
        for (int c = 1; c < col; c++) {
          m[r][c] = 0;
        }
      }
    }
    for (int c = 1; c < col; c++) {
      if (m[0][c] == 0) {
        for (int r = 1; r < row; r++) {
          m[r][c] = 0;
        }
      }
    }
    if (r0 == 0) {
      for (int r = 0; r < row; r++) {
        m[r][0] = 0;
      }
    }
    if (c0 == 0) {
      for (int c = 0; c < col; c++) {
        m[0][c] = 0;
      }
    }

  }
};
