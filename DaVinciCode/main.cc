#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Build Fibonacci index lookup.
  unordered_map<int, int> lookup;
  lookup[1] = 0;
  lookup[2] = 1;
  int prev = 2, prev_prev = 1, i = 2;
  int sum = prev + prev_prev;
  while (sum > 0) {
    lookup[sum] = i++;
    prev_prev = prev;
    prev = sum;
    sum = prev + prev_prev;
  }

  string input;
  getline(cin, input);
  size_t cases = stoll(input);
  while (cases--) {
    getline(cin, input);
    size_t num_fibs = stoll(input);
    getline(cin, input);
    istringstream iss(input);
    vector<int> fibs(num_fibs);
    for (size_t i = 0; i < num_fibs; i++) {
      iss >> fibs[i];
    }
    size_t max_fib_index = lookup[*max_element(fibs.begin(), fibs.end())];
    vector<char> chars(max_fib_index + 1);
    getline(cin, input);
    size_t i = 0, j = 0;
    while (i < num_fibs) {
      while (!isupper(input[j])) {
        j++;
      }
      chars[lookup[fibs[i++]]] = input[j++];
    }
    for (size_t i = 0; i < chars.size(); i++) {
      if (chars[i] == 0) {
        cout << ' ';
      } else {
        cout << chars[i];
      }
    }
    cout << '\n';
  }
  return 0;
}
