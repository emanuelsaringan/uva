#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

namespace {

void PrintCenterRadiusForm(double x, double y, double r) {
  ostringstream oss;
  oss << setprecision(3) << fixed;
  if (x == 0) {
    oss << "x";
  } else {
    oss << "(x " << (x < 0 ? '+' : '-') << " " << abs(x) << ")";
  }
  oss << "^2 + ";
  if (y == 0) {
    oss << "y";
  } else {
    oss << "(y " << (y < 0 ? '+' : '-') << " " << abs(y) << ")";
  }
  oss << "^2 = " << r << "^2\n";
  cout << oss.str();
}

void PrintGeneralForm(double x, double y, double r) {
  ostringstream oss;
  oss << setprecision(3) << fixed;
  double A = -2 * x;
  double B = -2 * y;
  double C = (x * x + y * y) - (r * r);
  oss << "x^2 + y^2 ";
  if (A != 0) {
    oss << (A < 0 ? '-' : '+') << " " << abs(A) << "x ";
  }
  if (B != 0) {
    oss << (B < 0 ? '-' : '+') << " " << abs(B) << "y ";
  }
  if (C != 0) {
    oss << (C < 0 ? '-' : '+') << " " << abs(C) << " ";
  }
  oss << "= 0\n";
  cout << oss.str();
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  double x1, y1, x2, y2, x3, y3;
  while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    if (y1 == y2) {
      swap(x1, x3);
      swap(y1, y3);
    }
    double slope12 = (y2 - y1) / (x2 - x1);
    slope12 = -1 / slope12;
    double mid12x = (x1 + x2) / 2;
    double mid12y = (y1 + y2) / 2;
    double b12 = mid12y - slope12 * mid12x;

    if (y2 == y3) {
      swap(x2, x1);
      swap(y2, y1);
    }
    double slope23 = (y3 - y2) / (x3 - x2);
    slope23 = -1 / slope23;
    double mid23x = (x2 + x3) / 2;
    double mid23y = (y2 + y3) / 2;
    double b23 = mid23y - slope23 * mid23x;

    double centerX = (b23 - b12) / (slope12 - slope23);
    double centerY = slope12 * centerX + b12;
    double radius = sqrt(pow(x1 - centerX, 2) + pow(y1 - centerY, 2));

    PrintCenterRadiusForm(centerX, centerY, radius);
    PrintGeneralForm(centerX, centerY, radius);
    cout << '\n';
  }
  return 0;
}
