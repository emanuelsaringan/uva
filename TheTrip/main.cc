#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n;
  cin >> n;
  cout << setprecision(2) << fixed;
  while (n != 0) {
    vector<double> v(n);
    double total = 0.0;
    for (size_t i = 0; i < n; i++) {
      cin >> v[i];
      total += v[i];
    }
    double avg = total / n;
    double positive_diff = 0.0;
    double negative_diff = 0.0;
    for (double vi : v) {
      double diff = static_cast<long>((vi - avg) * 100) / 100.0;
      if (diff > 0) {
        positive_diff += diff;
      } else if (diff < 0) {
        negative_diff += -diff;
      }
    }
    if (positive_diff > negative_diff) {
      cout << "$" << positive_diff << endl;
    } else {
      cout << "$" << negative_diff << endl;
    }
    cin >> n;
  }
  return 0;
}
