#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace {

char GetSoundexCode(char c) {
  switch (c) {
    case 'B':
    case 'F':
    case 'P':
    case 'V':
      return '1';
    case 'C':
    case 'G':
    case 'J':
    case 'K':
    case 'Q':
    case 'S':
    case 'X':
    case 'Z':
      return '2';
    case 'D':
    case 'T':
      return '3';
    case 'L':
      return '4';
    case 'M':
    case 'N':
      return '5';
    case 'R':
      return '6';
  }
  return '\0';
}

void Compress(string& str, string* soundex) {
  for (string::iterator it = str.begin(); it != str.end(); ++it) {
    char cur_code = GetSoundexCode(*it);
    if (cur_code == '\0') {
      continue;
    }
    while (it + 1 != str.end() && cur_code == GetSoundexCode(*(it + 1))) {
      str.erase(it + 1);
    }
    *soundex += cur_code;
  }
}

} // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ostringstream oss;

  string line, soundex;
  while (getline(cin, line)) {
    Compress(line, &soundex);
    oss << soundex << endl;
    soundex.clear();
  }
  cout << oss.str();
  return 0;
}
