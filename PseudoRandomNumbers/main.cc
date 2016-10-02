#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long Z, I, M, L;
  cin >> Z >> I >> M >> L;
  int c = 1;
  while (Z != 0 || I != 0 || M != 0 || L != 0) {
    int next = (Z * L + I) % M;
    unordered_set<int> mem;
    while (mem.insert(next).second) {
      next = (Z * next + I) % M;
    }
    cout << "Case " << c++ << ": " << mem.size() << '\n';
    cin >> Z >> I >> M >> L;
  }
  return 0;
}
