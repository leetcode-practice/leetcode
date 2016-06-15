#include <vector>
using namespace std;

static const int N = 4;
static int DIR[4][2] = {
  {-1,0}, {0, -1}, {1, 0}, {0, 1}
};

class Solution {
private:
  vector<vector<int>> val;
  int row, col;

public:
  int longestIncreasingPath(vector<vector<int>>& m) {

    row = m.size();
    if (row == 0) return 0;
    col = m[0].size();
    if (col == 0) return 0;

    val.clear();
    val.resize(row);
    for (int r = 0; r < row; r++) {
      val[r].resize(col);
    }

    int max_length = 0;
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        int curr_length = longestIncreasingPathAt(m, r, c);
        if (curr_length > max_length) {
          max_length = curr_length;
        }
      }
    }

    return max_length;
  }

private:

  void debug_val(const char* msg) {
    printf("%s\n", msg);
    for (int r=0; r<row; r++){
      for (int c=0;c<col;c++) {
        printf("%d%c", val[r][c], (c==col-1?'\n':','));
      }
    }
    printf("\n");
  }

  bool isOutOfRange(int r, int c) {
    if (r < 0 || r >= row || c < 0 || c >= col) {
      return true;
    }
    return false;
  }

  int longestIncreasingPathAt(vector<vector<int>>& m, int r, int c) {
    if (val[r][c] != 0) {
      return val[r][c];
    }
    if (isOutOfRange(r, c)) {
      return 0;
    }
    int max_val = 1;
    for (int i=0;i<N; i++) {
      int rr = r + DIR[i][0];
      int cc = c + DIR[i][1];
      if (!isOutOfRange(rr, cc) && m[rr][cc] > m[r][c]) {
        int curr_val = 1 + longestIncreasingPathAt(m, rr, cc);
        max_val = (curr_val > max_val ? curr_val : max_val);
      }
    }
    val[r][c] = max_val;

    // printf("r = %d, c = %d\n", r, c);
    // debug_val("");

    return max_val;
  }
};
