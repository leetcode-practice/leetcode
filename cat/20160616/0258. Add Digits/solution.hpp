
class Solution {
public:
  int addDigits(int num) {
    int s = ((num/10 - 1) % 9 + (num % 10)) % 9 + 1;
    return s;
  }
};
