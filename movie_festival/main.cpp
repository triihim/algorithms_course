#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

struct Movie {
  unsigned int start;
  unsigned int end;
  bool operator<(const Movie& other) {
    return end < other.end;
  }
};

int main() {
  unsigned int n; std::cin >> n;
  std::vector<Movie> movies;
  for(unsigned int i = 0; i < n; i++) {
    unsigned int x, y;
    std::cin >> x >> y;
    movies.push_back(Movie {x, y});
  }

  std::sort(movies.begin(), movies.end());

  unsigned int canWatch = 1;
  unsigned int prevEnd = movies[0].end;
  for(const auto& m : movies) {
    if(m.end >= prevEnd && m.start >= prevEnd) {
      prevEnd = m.end;
      canWatch++;
    }
  }
    
  std::cout << canWatch << std::endl;

  return 0;
}