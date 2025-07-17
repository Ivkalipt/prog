#include <algorithm>
#include <iostream>
#include <vector>

void func(const std::vector<std::vector<int>> &arr) {
  bool np1 = false;
  std::vector<int> np2;
  for (const auto &entry : arr) {
    int y = entry[0], m = entry[1], d = entry[2], t = entry[3], i = entry[4];
    if (t == 1) {
      np2.push_back(i);
      np1 = true;
    } else {
      if (np1) {
        for (const auto &val : np2) {
          std::cout << val << " ";
        }
        std::cout << std::endl;
        np1 = false;
      }
      np2.erase(std::remove(np2.begin(), np2.end(), i), np2.end());
    }
  }
}

int main() {
  std::vector<std::vector<int>> arr;
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    std::vector<int> date(6);
    for (int j = 0; j < 6; ++j) {
      std::cin >> date[j];
    }
    std::vector<int> a = {date[2] + 18, date[1], date[0], 1, i + 1};
    std::vector<int> b = {date[5], date[4], date[3], 0, i + 1};
    if (a < b) {
      arr.push_back(a);
      std::vector<int> old = {date[2] + 80, date[1], date[0], 0, i + 1};
      if (b < old) {
        arr.push_back(b);
      } else {
        arr.push_back(old);
      }
    }
  }
  if (arr.empty()) {
    std::cout << 0 << std::endl;
  } else {
    sort(arr.begin(), arr.end());
    func(arr);
  }
  return 0;
}
