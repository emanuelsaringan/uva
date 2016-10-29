#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);

  int cases;
  cin >> cases;
  while (cases--) {
    double a, b, c, R1, R2, R3;
    cin >> R1 >> R2 >> R3;
    a = R2 + R3;
    b = R1 + R3;
    c = R1 + R2;
    double A = acos((pow(c, 2) + pow(b, 2) - pow(a, 2)) / (2 * c * b));
    double B = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c));
    double C = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
    double a_area = (pow(R1, 2) / 2) * A;
    double b_area = (pow(R2, 2) / 2) * B;
    double c_area = (pow(R3, 2) / 2) * C;
    double s = (a + b + c) / 2;  // semiperimeter.
    double triangle_area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << (triangle_area - (a_area + b_area + c_area)) << '\n';
  }
  return 0;
}
