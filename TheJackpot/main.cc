#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace {

// Kadane's algorithm for finding the maximum contiguous sum.
int Kadane(const vector<int>& v) {
  int max = 0;
  int total = 0;
  for (int v_i : v) {
    total = std::max(0, total + v_i);
    max = std::max(max, total);
  }
  return max;
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t N;
  cin >> N;
  while (N != 0) {
    vector<int> v(N);
    for (size_t i = 0; i < N; i++) {
      cin >> v[i];
    }
    int result = Kadane(v);
    if (result > 0) {
      cout << "The maximum winning streak is " << result << ".\n";
    } else {
      cout << "Losing streak.\n";
    }
    cin >> N;
  }
  return 0;
}
