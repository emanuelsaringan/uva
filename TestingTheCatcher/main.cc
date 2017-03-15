#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace {

int LCS(const vector<int>& a, const vector<int>& b) {
  size_t N = a.size();
  vector<vector<int>> table(N + 1);
  for (size_t i = 0; i <= N; i++) {
    table[i] = vector<int>(N + 1);
  }
  for (size_t i = 1; i <= N; i++) {
    for (size_t j = 1; j <= N; j++) {
      if (a[i - 1] == b[j - 1]) {
        table[i][j] = 1 + table[i - 1][j - 1];
      } else {
        table[i][j] = max(table[i][j - 1], table[i - 1][j]);
      }
    }
  }
  return table[N][N];
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t case_num = 1;
  int n;
  cin >> n;
  while (n != -1) {
    vector<int> heights;
    heights.push_back(n);
    cin >> n;
    while (n != -1) {
      heights.push_back(n);
      cin >> n;
    }
    vector<int> sorted = heights;
    sort(sorted.begin(), sorted.end());
    reverse(heights.begin(), heights.end());
    if (case_num > 1) {
      cout << '\n';
    }
    cout << "Test #" << case_num++ << ":\n";
    cout << "  maximum possible interceptions: " << LCS(sorted, heights)
         << '\n';
    cin >> n;
  }
  return 0;
}
