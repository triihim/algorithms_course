#include <iostream>
#include <vector>
#include <map>

int main() {
  size_t n, k; std::cin >> n >> k;
  auto xs = std::vector<size_t>(n);
  for(size_t i = 0; i < n; i++) std::cin >> xs[i];

  size_t i = 0, j = 0, solutions = 0, current = xs[i];

  auto seen = std::map<size_t, size_t>();

  while(i < n) {
    current = xs[j];
    seen[current] += 1;
    while(seen.size() > k) {
      solutions += j - i;
      current = xs[i];
      if(--seen[current] == 0) seen.erase(current);
      i++;
    }
    if(++j >= n) {
      size_t remaining = j - i;
      solutions += (remaining*(remaining+1) / 2);
      break;
    }
  }

  std::cout << solutions << std::endl;

  return 0;
}