#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

namespace {

void FloydWarshall(vector<vector<size_t>>& adj) {
  size_t N = adj.size();
  for (size_t k = 0; k < N; k++) {
    for (size_t i = 0; i < N; i++) {
      for (size_t j = 0; j < N; j++) {
        if (adj[i][k] + adj[k][j] < adj[i][j]) {
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << "SHIPPING ROUTES OUTPUT\n\n";
  size_t cases, case_num = 1;
  cin >> cases;
  while (cases--) {
    size_t M, N, P;
    cin >> M >> N >> P;
    unordered_map<string, size_t> warehouses;
    string warehouse;
    for (size_t i = 0; i < M; i++) {
      cin >> warehouse;
      warehouses[warehouse] = i;
    }
    vector<vector<size_t>> adj(M);
    for (size_t i = 0; i < M; i++) {
      adj[i] = vector<size_t>(M);
      for (size_t j = 0; j < M; j++) {
        adj[i][j] = numeric_limits<int>::max();
      }
    }
    string from, to;
    for (size_t i = 0; i < N; i++) {
      cin >> from >> to;
      adj[warehouses[from]][warehouses[to]] = 1;
      adj[warehouses[to]][warehouses[from]] = 1;
    }
    FloydWarshall(adj);
    cout << "DATA SET  " << case_num++ << "\n\n";
    size_t shipment_size;
    for (size_t i = 0; i < P; i++) {
      cin >> shipment_size >> from >> to;
      size_t distance = adj[warehouses[from]][warehouses[to]];
      if (distance == numeric_limits<int>::max()) {
        cout << "NO SHIPMENT POSSIBLE\n";
      } else {
        cout << '$' << (shipment_size * distance * 100) << '\n';
      }
    }
    cout << '\n';
  }
  cout << "END OF OUTPUT\n";
  return 0;
}
