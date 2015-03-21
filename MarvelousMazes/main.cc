#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ostringstream oss;

  string line;
  while (getline(cin, line)) {
    if (line.empty()) {
      oss << endl;
      continue;
    }
    int count = 0;
    for (int i = 0; i < line.length(); i++) {
      char character = line[i] == 'b' ? ' ' : line[i];
      int digit = character - '0';
      if (0 <= digit && digit <= 9) {
        count += digit;
      } else if (character == '!') {
        oss << endl;
      } else {
        for (int j = 0; j < count; j++) {
          oss << character;
        }
        count = 0;
      }
    }
    oss << endl;
  }
  cout << oss.str();
  return 0;
}
