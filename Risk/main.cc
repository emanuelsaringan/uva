#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

namespace {

void FloydWarshall(vector<vector<int>>& adj_mat) {
  for (size_t k = 0; k < 20; k++) {
    for (size_t i = 0; i < 20; i++) {
      for (size_t j = 0; j < 20; j++) {
        if (adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]) {
          adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
        }
      }
    }
  }
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t c = 1;
  size_t X, J;
  while (true) {
    // Initialize adjacency matrix.
    vector<vector<int>> adj_mat(20);
    for (size_t i = 0; i < 20; i++) {
      adj_mat[i] = vector<int>(20);
      for (size_t j = 0; j < adj_mat[i].size(); j++) {
        adj_mat[i][j] = 10000;
      }
    }
    for (size_t i = 0; i < 19; i++) {
      if (cin >> X) {
        for (size_t j = 0; j < X; j++) {
          cin >> J;
          adj_mat[i][J - 1] = 1;
          adj_mat[J - 1][i] = 1;
        }
      } else {
        return 0;
      }
    }
    FloydWarshall(adj_mat);
    size_t N, src, dest;
    cin >> N;
    cout << "Test Set #" << c++ << '\n';
    for (size_t i = 0; i < N; i++) {
      cin >> src >> dest;
      cout << setw(2) << src << " to " << setw(2) << dest << ": ";
      cout << adj_mat[src - 1][dest - 1] << '\n';
    }
    cout << '\n';
  }
  return 0;
}
