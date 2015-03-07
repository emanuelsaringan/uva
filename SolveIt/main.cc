#include <iostream>
#include <math.h>

using namespace std;

double sgn(double val) {
  return (0 < val) - (val < 0);
}

double eval(
    double x, double p, double q, double r, double s, double t, double u) {
  return p / exp(x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const double kEpsilon = 0.0000001;
  double p, q, r, s, t, u;
  while (cin >> p >> q >> r >> s >> t >> u) {
    double low = 0.0;
    double high = 1.0;
    double mid = (low + high) / 2.0;
    while (true) {
      double guess_val = eval(mid, p, q, r, s, t, u);
      if (fabs(guess_val) <= kEpsilon) {
        printf("%.4f\n", mid);
        break;
      }

      double l_bound = eval(low, p, q, r, s, t, u);
      double r_bound = eval(high, p, q, r, s, t, u);
      if (sgn(guess_val) == sgn(l_bound) && sgn(guess_val) == sgn(r_bound)) {
        printf("No solution\n");
        break;
      }

      if (sgn(guess_val) == sgn(l_bound)) {
        low = mid;
      } else {
        high = mid;
      }
      mid = (low + high) / 2.0;
    }
  }
  return 0;
}
