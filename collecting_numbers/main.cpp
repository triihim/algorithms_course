#include <iostream>
#include <vector>
#include <map>

int main() {
  unsigned int n; std::cin >> n;
  std::vector<unsigned int> xs(n);
  for(unsigned int i = 0; i < n; i++) std::cin >> xs[i];

  std::map<unsigned int, unsigned int> I;
  for(unsigned int i = 0; i < n; i++) I[xs[i]] = i;
  
  unsigned int r = 1;
  for(unsigned int i = 2; i <= n; i++)
    if(I[i-1] > I[i]) r++;

  std::cout << r << std::endl;

  return 0;
}