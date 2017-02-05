#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {

void Print(const vector<string>& v) {
  for (const string& v_i : v) {
    cout << v_i << '\n';
  }
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  size_t input;
  while (cin >> input) {
    if (input == 2) {
      Print({"00", "01", "81"});
    } else if (input == 4) {
      Print({"0000", "0001", "2025", "3025", "9801"});
    } else if (input == 6) {
      Print({"000000", "000001", "088209", "494209", "998001"});
    } else if (input == 8) {
      Print({
          "00000000", "00000001", "04941729", "07441984", "24502500",
          "25502500", "52881984", "60481729", "99980001"});
    }
  }
  return 0;
}
