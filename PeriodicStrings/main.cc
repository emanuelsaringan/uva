#include <iostream>
#include <string>

using namespace std;

namespace {

int Solve(const string& input) {
  for (size_t i = 1; i <= input.size(); i++) {
    if (((input.size() - i) % i) != 0) {
      continue;
    }
    bool matches = true;
    string prefix = input.substr(0, i);
    for (size_t j = i; j < input.size(); j += i) {
      if (input.substr(j, i) != prefix) {
        matches = false;
        break;
      }
    }
    if (matches) {
      return i;
    }
  }
  return 1;
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t cases;
  cin >> cases;
  string input;
  for (size_t i = 0; i < cases; i++) {
    cin >> input;
    if (i != 0) {
      cout << '\n';
    }
    cout << Solve(input) << '\n';
  }
  return 0;
}
