#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

namespace {

class UnionFind {
 public:
  UnionFind(size_t size) {
    elems_.resize(size);
    for (size_t i = 0; i < size; i++) {
      elems_[i] = i;
    }
  }

  void join(size_t a, size_t b) {
    size_t a_parent = find(a);
    elems_[a_parent] = b;
  }

  size_t find(size_t n) {
    while (elems_[n] != n) {
      n = elems_[n];
    }
    return n;
  }

 private:
  vector<size_t> elems_;
};

struct Edge {
  Edge(double s, double d, double dist)
      : source(s), dest(d), weight(dist) {}

  double source;
  double dest;
  double weight;
};

double GetDistance(pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(b.second - a.second, 2) + pow(b.first - a.first, 2));
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << setprecision(2) << fixed;
  size_t cases;
  cin >> cases;
  for (size_t i = 0; i < cases; i++) {
    size_t num_points;
    cin >> num_points;
    vector<pair<double, double>> points(num_points);
    for (size_t j = 0; j < num_points; j++) {
      cin >> points[j].first >> points[j].second;
    }
    vector<Edge> edges;
    for (size_t j = 0; j < points.size(); j++) {
      for (size_t k = j + 1; k < points.size(); k++) {
        edges.push_back(Edge(j, k, GetDistance(points[j], points[k])));
      }
    }
    sort(edges.begin(), edges.end(),
        [](const Edge& e1, const Edge& e2) -> bool {
            return e1.weight < e2.weight;
        });
    UnionFind uf(num_points);
    double total = 0.0;
    for (const Edge& edge : edges) {
      if (uf.find(edge.source) != uf.find(edge.dest)) {
        uf.join(edge.source, edge.dest);
        total += edge.weight;
      }
    }
    cout << total << '\n';
    if (i != cases - 1) {
      cout << '\n';
    }
  }
  return 0;
}
