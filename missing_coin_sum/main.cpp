#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long mcs(vector<long long> N) {
  sort(N.begin(), N.end());
  if(N[0] != 1 || N.size() <= 1) return 1;
  long long n = N.size();
  long long c = 1;
  long long r = 1;
  for(long long i = 1; i <= n; i++) {
    c = r + 1;
    if(c - N[i] >= 0)
      r = r + N[i];
    else
      break;
  }
  return c;
}

int main() {
  long long n; cin >> n;
  vector<long long> xs(n);
  for(long long i = 0; i < n; i++) cin >> xs[i];

  std::cout << mcs(xs) << std::endl;

  return 0;
}