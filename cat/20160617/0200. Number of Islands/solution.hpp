#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    row = grid.size();
    if (row == 0) { return 0; }
    col = grid[0].size();
    if (col == 0) { return 0; }

    parents.clear();
    parents.resize(row * col);
    fill(parents.begin(), parents.end(), -1);

    static const int N = 4;
    static int DIR[][2] = {
      {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };

    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (grid[r][c] == '0') {
          continue;
        }
        int curr = r * col + c;
        if (parents[curr] < 0) {
          parents[curr] = curr;
        }
        for (int i = 0; i < N; i++) {
          int rr = r + DIR[i][0];
          int cc = c + DIR[i][1];
          if (isOutOfRange(rr, cc)) {
            continue;
          }
          if (grid[rr][cc] == '0') {
            continue;
          }
          int next = rr * col + cc;
          if (parents[next] < 0) {
            parents[next] = next;
          }
          int p1 = findParent(curr);
          int p2 = findParent(next);
          if (p1 != p2) {
            parents[p2] = p1;
          }
        }
      }
    }

    int num = 0;
    for (int i = 0; i < parents.size(); i++) {
      if (parents[i] >= 0 && parents[i] == i) {
        num++;
      }
    }

    return num;
  }

private:
  int row, col;
  vector<int> parents;

  bool isOutOfRange(int r, int c) {
    return r < 0 || r >= row || c < 0 || c >= col;
  }

  int findParent(int idx) {
    if (parents[idx] < 0 || parents[idx] == idx) {
      return parents[idx];
    }
    int p = findParent(parents[idx]);
    parents[idx] = p;
    return p;
  }
};
