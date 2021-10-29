#include <iostream>
#include <vector>

int main() {
  unsigned long n;
  std::cin >> n;

  unsigned long s = (n*(n+1))/2;

  if(s % 2 != 0) {
    std::cout << "NO" << std::endl;
    return 0;
  } else {
    std::cout << "YES" << std::endl;
  }

  unsigned long mid = s / 2;
  unsigned long aSum = 0;
  std::vector<unsigned long> a;
  std::vector<unsigned long> b;
  for(unsigned long i = 0; i < n; i++) {
    int x = n - i;
    if(aSum + x <= mid) {
      a.push_back(x);
      aSum += x;
    } else {
      b.push_back(x);
    }
  }

  std::cout << a.size() << std::endl;  
  for(size_t i = 0; i < a.size(); i++) std::cout << a[i] << " ";
  std::cout << std::endl << b.size() << std::endl;
  for(size_t i = 0; i < b.size(); i++) std::cout << b[i] << " ";

  return 0;
}