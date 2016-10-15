#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

namespace {

static const char kEmpty = '\0';

void Flood(vector<vector<char>>& grid, int i, int j, char c) {
  if (i < 0 || i >= grid.size() || j < 0 || j > grid[i].size()) {
    return;
  }
  if (c == kEmpty || grid[i][j] != c) {
    return;
  }
  grid[i][j] = kEmpty;
  Flood(grid, i - 1, j, c);
  Flood(grid, i + 1, j, c);
  Flood(grid, i, j - 1, c);
  Flood(grid, i, j + 1, c);
}

void TallyLanguages(
    vector<vector<char>>& grid, unordered_map<char, int>& tally) {
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid[i].size(); j++) {
      char c = grid[i][j];
      if (c != kEmpty) {
        tally[c]++;
        Flood(grid, i, j, c);
      }
    }
  }
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t world_num = 1;
  size_t cases;
  cin >> cases;
  while (cases--) {
    size_t H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H);
    for (size_t i = 0; i < H; i++) {
      grid[i] = vector<char>(W);
    }
    string line;
    for (size_t i = 0; i < H; i++) {
      cin >> line;
      for (size_t j = 0; j < W; j++) {
        grid[i][j] = line[j];
      }
    }
    unordered_map<char, int> tally;
    TallyLanguages(grid, tally);
    cout << "World #" << world_num++ << '\n';
    vector<pair<char, int>> sorted(tally.begin(), tally.end());
    sort(sorted.begin(), sorted.end(),
        [](const pair<char, int>& p1, const pair<char, int>& p2) {
          if (p1.second == p2.second) {
            return p1.first < p2.first;
          }
          return p1.second > p2.second;
        });
    for (const pair<char, int>& p : sorted) {
      cout << p.first << ": " << p.second << '\n';
    }
  }
  return 0;
}
