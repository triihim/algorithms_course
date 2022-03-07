#include <iostream>
#include <vector>

const long long mod = 1e9 + 7;

int main() {
  long long n; std::cin >> n;
  if((n*(n+1)/2) % 2 == 0) {
    long long half = n*(n+1)/4;
    std::vector<long long> dp(half+1);
    dp[0] = 1;
    for(long long i = 1; i <= n; i++){
      for(long long j = half; j >= i; j--) {
        dp[j] = (dp[j] + dp[j - i]) % mod;
      }
    }
    auto result = (dp[half] * 500000004) % mod;
    std::cout << result << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}