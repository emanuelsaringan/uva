#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace {

long Solve(const vector<int>& S) {
  long max_product = 0, cur_product;
  for (size_t i = 0; i < S.size(); i++) {
    cur_product = 1;
    for (size_t j = i; j < S.size(); j++) {
      cur_product *= S[j];
      if (cur_product > 0 && cur_product > max_product) {
        max_product = cur_product;
      }
    }
  }
  return max_product;
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  int N = 0, case_num = 1;
  while (getline(cin, line)) {
    istringstream iss(line);
    if (N == 0) {
      iss >> N;
    } else if (line == "") {
      // Do nothing.
    } else {
      vector<int> S(N);
      for (size_t i = 0; i < N; i++) {
        iss >> S[i];
      }
      cout << "Case #" << case_num++ << ": The maximum product is "
           << Solve(S) << ".\n\n";
      N = 0;
    }
  }
  return 0;
}
