#include <vector>

class Solution {
public:
  int calculate(string str) {
    if (str.empty()) {
      return 0;
    }
    curr = 0;
    len = str.size();
    s = str;

    int val = expression();
    return val;
  }

private:

  string s;
  int curr;
  int len;

  int expression() {
    int res = term();
    while (curr < len) {
      skip();
      if (s[curr] == '+') {
        curr++;
        int val = term();
        res += val;
      } else if (s[curr] == '-') {
        curr++;
        int val = term();
        res -= val;
      } else if (s[curr] == ')') {
        break;
      }
    }
    return res;
  }

  int term() {
    skip();
    if (s[curr] >= '0' && s[curr] <= '9') {
      int val = digits();
      return val;
    }
    if (s[curr] == '(') {
      curr++;
      int val = expression();
      skip();
      if (s[curr] == ')') {
        curr++;
      } else {
        // should not arrive here
      }
      return val;
    }
    // should not arrive here
    return 0;
  }

  int digits() {
    int val = 0;
    while (curr < len && s[curr] >= '0' && s[curr] <= '9') {
      val = val * 10 + (s[curr] - '0');
      curr++;
    }
    return val;
  }

  void skip() {
    while (curr < len && s[curr] == ' ') {
      curr++;
    }
  }

};
