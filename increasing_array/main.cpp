#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template<typename T> std::vector<T> readNumberLine() {
  std::vector<T> numbers;
  std::string input;
  std::getline(std::cin, input);
  std::istringstream iss(input);
  T x;
  while(iss >> x) numbers.push_back(x);
  return numbers;
}

template<typename T> T readNumber() {
  T n;
  std::cin >> n;
  std::cin.ignore();
  return n;
}

int main() {
  unsigned int n = readNumber<unsigned int>();
  std::vector<unsigned int> xs = readNumberLine<unsigned int>();

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

  std::cout << std::endl;
  std::cout << moves << std::endl;

  return 0;
}