#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class UnionFind {
 public:
  explicit UnionFind(int size) {
    for (int i = 0; i < size; i++) {
      root[i] = i;
    }
  }

  void unite(int a, int b) {
    int a_root = find(a);
    int b_root = find(b);
    if (a_root != b_root) {
      for (auto& iter : root) {
        if (iter.second == b_root) {
          iter.second = a_root;
        }
      }
    }
  }

  int find(int node) {
    std::unordered_map<int, int>::iterator root_iter = root.find(node);
    return root_iter != root.end() ? (*root_iter).second : -1;      
  }

  void clear() {
    root.clear();
  }
 private:
  std::unordered_map<int, int> root;
};

struct Edge {
  Edge(int a, int b, int c) : x(a), y(b), weight(c) {}
  int x, y, weight;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n;
  cin >> m >> n;
  while (m != 0 || n != 0) {
    vector<Edge> edges;
    int x, y, z, total = 0;
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> z;
      total += z;
      edges.emplace_back(x, y, z);
    }

    // Kruskal's Algorithm for finding the Minimum Cost Spanning Tree.
    sort(edges.begin(), edges.end(),
        [](const Edge& e1, const Edge& e2) -> bool {
          return e1.weight < e2.weight;
        });
    UnionFind uf(m);
    int mcst = 0;
    for (const auto& e : edges) {
      if (uf.find(e.x) != uf.find(e.y)) {
        mcst += e.weight;
        uf.unite(e.x, e.y);
      }
    }
    cout << (total - mcst) << endl;
    cin >> m >> n;
  }
  return 0;
}
