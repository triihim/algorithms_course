#include <iostream>
#include <vector>

using namespace std;

void josephus(vector<uint32_t> xs, bool odds = true) {
  if(xs.size() == 1) {
    cout << xs[0] << endl;
  } else {
    vector<uint32_t> ys;
    uint32_t last;
    for(uint32_t i = 0; i < xs.size(); i++) {
      if( (odds && i % 2 == 1) || (!odds && i % 2 == 0) ) {
        cout << xs[i] << " ";
        last = i;
      } else {
        ys.push_back(xs[i]);
      }
    }
    josephus(ys, last == xs.size()-1);
  }
}

int main() {
  uint32_t n; cin >> n;
  vector<uint32_t> xs;
  for(uint32_t i = 1; i <= n; i++) xs.push_back(i);
  josephus(xs);
}
