#include <iostream>
#include <vector>
#include <map>
#include <sstream>

template<typename T> T readNumber() {
  T n;
  std::cin >> n;
  std::cin.ignore();
  return n;
}

template<typename T> std::vector<T> readNumberLine() {
  std::vector<T> numbers;
  std::string input;
  std::getline(std::cin, input);
  std::istringstream iss(input);
  T x;
  while(iss >> x) numbers.push_back(x);
  return numbers;
}

int main() {
  unsigned int n = readNumber<unsigned int>();
  std::vector<unsigned int> xs = readNumberLine<unsigned int>();

  std::map<unsigned int, unsigned int> I;
  for(unsigned int i = 0; i < n; i++) I[xs[i]] = i;
  
  unsigned int r = 1;
  for(unsigned int i = 2; i <= n; i++)
    if(I[i-1] > I[i]) r++;

  std::cout << r << std::endl;

  return 0;
}