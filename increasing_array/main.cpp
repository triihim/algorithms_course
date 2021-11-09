#include <iostream>
#include <vector>

int main() {
  unsigned int n; std::cin >> n;
  std::vector<unsigned int> xs(n);
  for(unsigned int i = 0; i < n; i++) std::cin >> xs[i];

  unsigned int max = xs[0];
  long long moves = 0;

  for(unsigned int i = 1; i < n; i++) {
    if(xs[i] < max) {
      moves += (max - xs[i]);
    }
    if(xs[i] > max) {
      max = xs[i];
    }
  }

  std::cout << moves << std::endl;

  return 0;
}