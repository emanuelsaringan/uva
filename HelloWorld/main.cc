#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  size_t c = 1;
  cin >> n;
  while (n > 0) {
    cout << "Case " << c++ << ": " << ceil(log2(n)) << '\n';
    cin >> n;
  }
  return 0;
}
