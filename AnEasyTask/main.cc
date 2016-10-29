#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(2);

  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  while (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) {
    // Cramer's rule.
    double den = a * e - b * d;
    if (den != 0) {
      double x = (c * e - f * b) / den;
      double y = (a * f - d * c) / den;
      if (x == 0) {
        x = abs(x);
      }
      if (y == 0) {
        y = abs(y);
      }
      cout << "The fixed point is at " << x << " " << y << ".\n";
    } else {
      cout << "No fixed point exists.\n";
    }
    cin >> a >> b >> c >> d >> e >> f;
  }
  return 0;
}
