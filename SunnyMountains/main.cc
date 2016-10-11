#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

namespace {

double GetSlope(const pair<double, double> p1, const pair<double, double> p2) {
  return (p2.second - p1.second) / (p2.first - p1.first);
}

double GetDistance(
    const pair<double, double> p1, const pair<double, double> p2) {
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(2) << fixed;

  int cases;
  cin >> cases;
  while (cases--) {
    int N;
    cin >> N;
    vector<pair<double, double>> points(N);
    for (int i = 0; i < N; i++) {
      cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end(),
        [](const pair<double, double>& p1, const pair<double, double>& p2){
          return p1.first < p2.first;
        });
    double total = 0.0;
    double max_height = 0.0;
    for (int i = points.size() - 1; i > 0; i--) {
      if (max_height >= points[i - 1].second) {
        continue;
      }
      double m = GetSlope(points[i], points[i - 1]);
      if (m >= 0) {
        continue;
      }
      double b = points[i].second - m * points[i].first;
      pair<double, double> start_point = make_pair(
          (max_height - b) / m, max_height);
      total += GetDistance(start_point, points[i - 1]);
      max_height = points[i - 1].second;
    }
    cout << total << '\n';
  }
  return 0;
}
