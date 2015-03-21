#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

namespace {

bool GetNext(string& input) {
  int start_idx = -1;
  int swap_idx = -1;
  for (int i = input.length() - 1; i >= 1; i--) {
    if (input[i - 1] < input[i]) {
      start_idx = i - 1;
      break;
    }
  }
  if (start_idx == -1) {
    return false;
  }
  char start_char = input[start_idx];
  for (int i = input.length() - 1; i > start_idx; i--) {
    if (input[i] > start_char) {
      swap_idx = i;
      break;
    }
  }
  swap(input[start_idx], input[swap_idx]);
  sort(input.begin() + start_idx + 1, input.end());
  return true;
}

} // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string input;
  cin >> input;
  while (input != "#") {
    if (GetNext(input)) {
      cout << input << endl;
    } else {
      cout << "No Successor" << endl;
    }
    cin >> input;
  }
  return 0;
}
