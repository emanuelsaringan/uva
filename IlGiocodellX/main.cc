#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {

bool Connected(vector<vector<char>>& grid, int i, int j, int N) {
  if (i < 0 || i >= N || j < 0 || j >= N) {
    return false;
  }
  if (grid[i][j] != 'w') {
    return false;
  }
  if (j == N - 1) {
    return true;
  }
  grid[i][j] = '\0';
  return Connected(grid, i - 1, j - 1, N) ||
      Connected(grid, i - 1, j, N) ||
      Connected(grid, i, j - 1, N) ||
      Connected(grid, i, j + 1, N) ||
      Connected(grid, i + 1, j, N) ||
      Connected(grid, i + 1, j + 1, N);
}

bool IsWhiteWinner(vector<vector<char>>& grid) {
  for (size_t i = 0; i < grid.size(); i++) {
    if (Connected(grid, i, 0, grid.size())) {
      return true;
    }
  }
  return false;
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t N, c = 1;
  string line;
  cin >> N;
  while (N != 0) {
    vector<vector<char>> grid(N);
    for (size_t i = 0; i < N; i++) {
      grid[i] = vector<char>(N);
      cin >> line;
      for (size_t j = 0; j < N; j++) {
        grid[i][j] = line[j];
      }
    }
    cout << c++ << " " << (IsWhiteWinner(grid) ? "W" : "B") << '\n';
    cin >> N;
  }
  return 0;
}
