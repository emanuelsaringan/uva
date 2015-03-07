#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ostringstream oss;

  const char kRight = 'R';
  const char kLeft = 'L';

  int num, den;
  cin >> num >> den;
  while (num != 1 || den != 1) {
    vector<char> steps;
    int m = 0, m_ = 1;
    int n = 1, n_ = 0;
    while (true) {
      int mm_ = m + m_;
      int nn_ = n + n_;

      if (mm_ * den < num * nn_) {
        m = mm_;
        n = nn_;
        steps.push_back(kRight);
      } else if (mm_ * den > num * nn_) {
        m_ = mm_;
        n_ = nn_;
        steps.push_back(kLeft);
      } else {
        break;
      }
    }

    oss << string(steps.begin(), steps.end()) << endl;
    cin >> num >> den;
  }
  cout << oss.str();
  return 0;
}
