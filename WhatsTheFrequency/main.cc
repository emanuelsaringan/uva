#include <cctype>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ostringstream oss;

  string line;
  while (getline(cin, line)) {
    map<char, int> tally;
    int max = INT_MIN;
    for (const char& c : line) {
      if (!isalpha(c)) {
        continue;
      }
      tally[c]++;
      if (tally[c] > max) {
        max = tally[c];
      }
    }
    for (const auto& t : tally) {
      if (max == t.second) {
        oss << t.first;
      }
    }
    oss << " " << max << endl;
  }
  cout << oss.str();
  return 0;
}
