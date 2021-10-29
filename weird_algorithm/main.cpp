#include <iostream>

int main() {
  long long n;
  std::cin >> n;
  std::cout << n << " ";

  while(n > 1) {
    n = n % 2 == 0 ? n / 2 : n * 3 + 1;
    std::cout << n << " ";
  }

  std::cout << std::endl;

  return 0;
}