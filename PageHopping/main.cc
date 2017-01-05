#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

namespace {

static const int kInfinity = 100000;
static const int kRange = 100;

double FloydWarshall(vector<vector<int>>& grid, const set<int>& pages) {
  for (int k = 0; k < kRange; k++) {
    for (int i = 0; i < kRange; i++) {
      for (int j = 0; j < kRange; j++) {
        if (grid[i][j] > grid[i][k] + grid[k][j]) {
          grid[i][j] = grid[i][k] + grid[k][j];
        }
      }
    }
  }
  double total = 0.0;
  for (int p_i : pages) {
    for (int p_j : pages) {
      if (p_i == p_j) {
        continue;
      }
      total += grid[p_i][p_j];
    }
  }
  return total;
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(3) << fixed;

  int src, dest, c = 1;
  cin >> src >> dest;
  while (src != 0 || dest != 0) {
    // Initialize adjacency matrix.
    vector<vector<int>> grid(kRange);
    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < kRange; j++) {
        grid[i].push_back(kInfinity);
      }
    }
    // Populate adjacency matrix.
    set<int> pages;
    pages.insert(src - 1);
    pages.insert(dest - 1);
    grid[src - 1][dest - 1] = 1;
    cin >> src >> dest;
    while (src != 0 || dest != 0) {
      pages.insert(src - 1);
      pages.insert(dest - 1);
      grid[src - 1][dest - 1] = 1;
      cin >> src >> dest;
    }
    cout << "Case " << c++ << ": average length between pages = " <<
      FloydWarshall(grid, pages) / (pages.size() * (pages.size() - 1))
      << " clicks"  << endl;
    cin >> src >> dest;
  }
  return 0;
}
