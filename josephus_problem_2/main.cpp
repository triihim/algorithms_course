#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<size_t, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
  size_t n, k; std::cin >> n >> k;
  indexed_set s;
  for(size_t i = 1; i <= n; i++) s.insert(i);

  std::vector<size_t> solution;
  size_t i = k % n;
  size_t c;

  while(!s.empty()) {
    c = *(s.find_by_order(i));
    solution.push_back(c);
    s.erase(c);
    n = s.size();
    i = (i + k) % (n > 0 ? n : 1);
  }

  for(const auto& x : solution) 
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
