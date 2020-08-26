#include <limits.h>
#include <string>
int myatoi(std::string str) {
  if (str.size() == 0)
    return 0;
  int ans = 0, idx = 0, bol = 1;
  while (idx < str.size() && str[idx] == ' ')
    idx++;
  if (str[idx] == '-' || str[idx] == '+') {
    if (str[idx++] == '-')
      bol = -1;
  }
  while (idx < str.size() && str[idx] >= '0' && str[idx] <= '9') {
    int cur = str[idx] - '0';
    if (bol == 1 && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && cur > 7)))
      return INT_MAX;
    if (bol == -1 &&
        (-ans < INT_MIN / 10 || (-ans == INT_MIN / 10 && cur >= 8)))
      return INT_MIN;
    ans = ans * 10 + cur;
    idx++;
  }

  return ans * bol;
}