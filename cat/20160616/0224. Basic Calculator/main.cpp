#include <vector>
#include <string>
using namespace std;

#include "solution.hpp"

int main() {
  Solution s;
  vector<string> testcases = {
    "1+ 1",
    " 2-1 + 2 ",
    "(1+(4+5+2)-3)+(6+8)"
  };
  for (int i=0;i < testcases.size(); i++) {
    int v = s.calculate(testcases[i]);
    printf("%s = %d\n", testcases[i].c_str(), v);
  }
  return 0;
}
