#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace {

struct Edge {
  Edge(size_t u, size_t v, int w) : src(u), dest(v), weight(w) {}

  size_t src;
  size_t dest;
  int weight;
};

class UnionFind {
  public:
    UnionFind(size_t size) : v_(size) {
      for (size_t i = 0; i < size; i++) {
        v_[i] = i;
      }
    }

    void Join(size_t u, size_t v) {
      v_[Find(u)] = Find(v);
    }

    size_t Find(size_t u) {
      size_t cur = u;
      while (v_[cur] != cur) {
        cur = v_[cur];
      }
      return cur;
    }

  private:
    vector<size_t> v_;
};

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, u, v, w;
  cin >> n >> m;
  while (n != 0 || m != 0) {
    vector<Edge> edges;
    while (m--) {
      cin >> u >> v >> w;
      edges.emplace_back(u, v, w);
    }
    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
      return e1.weight < e2.weight;
    });
    UnionFind uf(n);
    vector<size_t> results;
    for (const Edge& e : edges) {
      if (uf.Find(e.src) != uf.Find(e.dest)) {
        uf.Join(e.src, e.dest);
      } else {
        results.push_back(e.weight);
      }
    }
    if (results.empty()) {
      cout << "forest" << endl;
    } else {
      bool first = true;
      sort(results.begin(), results.end());
      for (size_t result : results) {
        if (first) {
          first = false;
        } else {
          cout << " ";
        }
        cout << result;
      }
      cout << endl;
    }
    cin >> n >> m;
  }
  return 0;
}
