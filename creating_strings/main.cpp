#include <iostream>
#include <string>
#include <vector>
#include <set>

std::string removeCharAtIndex(size_t index, std::string s) {
  return s.erase(index, 1);
}

void permutations_(std::string s, std::string r, std::set<std::string>& p) {
  if(r.length() == 0) p.insert(s);
  for(size_t i = 0; i < r.length(); i++) 
    permutations_(s + r[i], removeCharAtIndex(i, r), p);
}

std::set<std::string> permutations(std::string s) {
  std::set<std::string> P;
  for(size_t i = 0; i < s.length(); i++)
    permutations_(std::string(1, s[i]), removeCharAtIndex(i, s), P);
  return P;
}

int main() {
  std::string s;
  std::getline(std::cin, s);

  std::set<std::string> result = permutations(s);

  std::cout << result.size() << std::endl;

  for(const std::string& p : result)
    std::cout << p << std::endl;

  return 0;
}