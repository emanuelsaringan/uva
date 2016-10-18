#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

#define PI acos(-1)

using namespace std;

namespace {

static const int kEarthDiameter = 6440;

double ToRad(double deg) {
  return deg / 180.0 * PI;
}

double ComputeArc(int s, double deg) {
  return (((s + kEarthDiameter) * 2) / 360.0) * deg * PI;
}

double ComputeChord(int s, double deg) {
  if (deg == 180.0) {
    return 2 * (s + kEarthDiameter);
  }
  double deg2 = (180 - deg) / 2;
  double rad = ToRad(deg);
  double rad2 = ToRad(deg2);
  return sin(rad) * ((s + kEarthDiameter) / sin(rad2));
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << setprecision(6) << fixed;
  int s, a;
  string unit;
  double deg;
  while (cin >> s >> a >> unit) {
    if (unit == "min") {
      deg = a / 60.0;
    } else {
      deg = a;
    }
    deg = min(deg, 360 - deg);
    cout << ComputeArc(s, deg) << " "
         << ComputeChord(s, deg) << '\n';
  }
  return 0;
}
