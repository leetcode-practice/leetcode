#include <vector>
using namespace std;

// - Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// - Any live cell with two or three live neighbors lives on to the next generation.
// - Any live cell with more than three live neighbors dies, as if by over-population..
// - Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction

static const int N = 8;
static int DIR[N][2] = {
  {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

class Solution {

public:
  void gameOfLife(vector< vector<int> >& board) {
    int row = board.size();
    if (row == 0) return;
    int col = board[0].size();
    if (col == 0) return;

    prepareBoardNeighbors(board, row, col);

    makeNextGenerationNeighbors(board, row, col);
  }

private:

  bool isAlive(const vector< vector<int> >& board, int r, int c) {
    return (board[r][c] & 0xFF) == 1;
  }

  bool isOutOfRange(int r, int c, int row, int col) {
    return r < 0 || r >= row || c < 0 || c >= col;
  }

  void prepareBoardNeighbors(vector< vector<int> >& board, int row, int col) {
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        for (int i=0; i < N; i++) {
          int rr = r + DIR[i][0];
          int cc = c + DIR[i][1];
          if (isOutOfRange(rr, cc, row, col)) {
            continue;
          }
          board[rr][cc] += ((board[r][c] & 0xFF) << 8);
        }
      }
    }
  }

  void makeNextGenerationNeighbors(vector< vector<int> >& board, int row, int col) {
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        int cnt = ((board[r][c] >> 8) & 0xFF);
        if (isAlive(board, r, c)) {
          if (cnt < 2) {
            board[r][c] = 0; // die
          } else if (cnt == 2 || cnt == 3) {
            board[r][c] = 1; // live
          } else {
            board[r][c] = 0; // die
          }
        } else {
          if (cnt == 3) {
            board[r][c] = 1;
          } else {
            board[r][c] = 0;
          }
        }
      }
    }
  }
};
