#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace {

// Returns the Longest Common Subsequence between |a| and |b|.
int LCS(const vector<int>& a, int M, const vector<int>& b, int N) {
  vector<vector<int>> grid(M + 1);
  for (size_t i = 0; i < grid.size(); i++) {
    grid[i] = vector<int>(N + 1);
  }
  for (size_t i = 1; i < grid.size(); i++) {
    for (size_t j = 1; j < grid[i].size(); j++) {
      if (a[i - 1] == b[j - 1]) {
        grid[i][j] = 1 + grid[i - 1][j - 1];
      } else {
        grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
      }
    }
  }
  return grid[M][N];
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> actual;
  string line;
  bool is_getting_answer = false;
  while (getline(cin, line)) {
    istringstream iss(line);
    vector<int> tokens;
    int num;
    while (iss >> num) {
      tokens.push_back(num);
    }
    if (tokens.size() == 1) {
      actual.resize(tokens.front());
      is_getting_answer = false;
    } else {
      if (!is_getting_answer) {
        for(size_t i = 0; i < tokens.size(); i++) {
          actual[tokens[i] - 1] = i;
        }
        is_getting_answer = true;
      } else {
        vector<int> answer(actual.size());
        for(size_t i = 0; i < tokens.size(); i++) {
          answer[tokens[i] - 1] = i;
        }
        cout << LCS(actual, actual.size(), answer, answer.size());
        cout << '\n';
      }
    }
  }
  return 0;
}
