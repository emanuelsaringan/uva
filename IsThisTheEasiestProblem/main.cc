#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace {

string Solve(vector<long>& sides) {
  for (long side : sides) {
    if (side <= 0) {
      return "Invalid";
    }
  }
  sort(sides.begin(),sides.end());
  if (sides[2] >= sides[0] + sides[1]) {
    return "Invalid";
  } else if (sides[0] == sides[1] && sides[1] == sides[2]) {
    return "Equilateral";
  } else if (sides[0] < sides[1] && sides[1] < sides[2]) {
    return "Scalene";
  }
  return "Isosceles";
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<long> sides(3);
  size_t cases;
  cin >> cases;
  for (size_t i = 1; i <= cases; i++) {
    cin >> sides[0] >> sides[1] >> sides[2];
    cout << "Case " << i << ": " << Solve(sides) << '\n';
  }
  return 0;
}
