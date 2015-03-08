#include <iostream>
#include <sstream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ostringstream oss;

  size_t cases;
  cin >> cases;
  for (size_t i = 0; i < cases; i++) {
    unsigned long long sum, diff;
    cin >> sum >> diff;
    if (sum < diff) {
      oss << "impossible" << endl;
    } else {
      unsigned long long sum_diff = sum + diff;
      if (sum_diff % 2 != 0) {
        oss << "impossible" << endl;
      } else {
        unsigned long long first = sum_diff >> 1;
        unsigned long long second = sum - first;
        oss << first << " " << second << endl;
      }
    }
  }
  cout << oss.str();
  return 0;
}
