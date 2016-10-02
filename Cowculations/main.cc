#include <iostream>
#include <string>

using namespace std;

namespace {

static const string kLookup = "VUCD";

int Convert(const string& num) {
  if (num.empty()) {
    return 0;
  }
  int result = kLookup.find(num[0]);
  for (int i = 1; i < num.size(); i++) {
    result = 4 * result + kLookup.find(num[i]);
  }
  return result;
}

string Format(int num) {
  string result;
  while (num != 0) {
    result = kLookup[num % 4] + result;
    num /= 4;
  }
  while (result.size() < 8) {
    result = "V" + result;
  }
  return result;
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t N;
  cin >> N;
  cout << "COWCULATIONS OUTPUT\n";
  for (size_t i = 0; i < N; i++) {
    string a, b;
    cin >> a >> b;
    int num1 = Convert(a);
    int num2 = Convert(b);
    for (size_t j = 0; j < 3; j++) {
      char op;
      cin >> op;
      if (op == 'A') {
        num2 += num1;
      } else if (op == 'R') {
        num2 /= 4;
      } else if (op == 'L') {
        num2 *= 4;
      } else {
        // NOP.
      }
    }
    string expected;
    cin >> expected;
    cout << (expected == Format(num2)? "YES" : "NO") << '\n';
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
