#include <string>

using namespace std;

class Solution {
public:
  string reverseString(string s) {
    if (s.empty()) {
      return s;
    }
    int f = 0;
    int t = s.length()-1;
    while (f < t) {
      char a = s[f];
      s[f] = s[t];
      s[t] = a;
      f++;
      t--;
    }
    return s;
  }
};
