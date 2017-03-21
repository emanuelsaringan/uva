#include <iostream>
#include <string>

using namespace std;

namespace {

int Period(const string& input) {
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

  string input;
  cin >> input;
  while (input != ".") {
    cout << input.size() / Period(input) << '\n';
    cin >> input;
  }
  return 0;
}
