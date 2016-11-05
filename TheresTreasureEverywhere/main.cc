#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace {

vector<string> Tokenize(const string& str, char delim) {
  vector<string> tokens;
  size_t cur = 0;
  size_t end = str.find(delim);
  while (end != string::npos) {
    tokens.push_back(str.substr(cur, end - cur));
    cur = end + 1;
    end = str.find(delim, cur);
  }
  tokens.push_back(str.substr(cur));
  return tokens;
}

}  // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(3);
  static const double kSqrt2 = sqrt(2);

  string line;
  size_t map_no = 1;
  while (getline(cin, line) && line != "END") {
    line.erase(line.length() - 1);  // Erase trailing '.'
    vector<string> instructions = Tokenize(line, ',');
    double x = 0.0;
    double y = 0.0;
    for (const string& ins : instructions) {
      size_t dir_idx = ins.find_first_of("NEWS");
      int unit = stoi(ins.substr(0, dir_idx));
      double diag_unit = unit / kSqrt2;
      string dir = ins.substr(dir_idx);
      if (dir == "N") {
        y += unit;
      } else if (dir == "E") {
        x += unit;
      } else if (dir == "W") {
        x -= unit;
      } else if (dir == "S") {
        y -= unit;
      } else if (dir == "NE") {
        x += diag_unit;
        y += diag_unit;
      } else if (dir == "NW") {
        x -= diag_unit;
        y += diag_unit;
      } else if (dir == "SE") {
        x += diag_unit;
        y -= diag_unit;
      } else if (dir == "SW") {
        x -= diag_unit;
        y -= diag_unit;
      }
    }
    cout << "Map #" << map_no++ << '\n';
    cout << "The treasure is located at (" << x << "," << y << ").\n";
    cout << "The distance to the treasure is " << hypot(x, y) << ".\n\n";
  }
  return 0;
}
