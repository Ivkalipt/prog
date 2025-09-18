#include <iostream>
#include <string>
using namespace std;

int main() {
  char input[81];
  cin.getline(input, 81);

  string res = "", curr = "";

  for (int i = 0; input[i] != '\0'; i++) {
    unsigned char c = input[i];
    if (c == '-' || (c >= 128 && c <= 255)) {
      curr += c;
    } else {
      if (!curr.empty()) {
        res.append(curr.rbegin(), curr.rend());
        curr.clear();
      }
      res += c;
    }
  }

  if (!curr.empty())
    res.append(curr.rbegin(), curr.rend());

  cout << res << '\n';
  return 0;
}
