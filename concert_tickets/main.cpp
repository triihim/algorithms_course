#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

int main() {
  uint32_t n, m; std::cin >> n; std::cin >> m;
  std::multiset<uint32_t, std::greater<uint32_t>> tickets;
  uint32_t temp = 0;
  for(uint32_t i = 0; i < n; i++) {
    std::cin >> temp;
    tickets.insert(temp);
  }

  uint32_t money = 0;
  while(m != 0) {
    std::cin >> money;
    auto it = tickets.lower_bound(money);
    if(it == tickets.end()) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << *it << std::endl;
      tickets.erase(it);
    }
    m--;
  }

  return 0;
}