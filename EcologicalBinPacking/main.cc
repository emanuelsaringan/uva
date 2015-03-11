#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

static const size_t kNumBottles = 9;

int GetTotalMoves(int total_bottles, string order, vector<int> bottles) {
  for (size_t i = 0; i < order.length(); i++) {
    char color = order[i];
    if (color == 'B') {
      total_bottles -= bottles[i * 3];
    } else if (color == 'G') {
      total_bottles -= bottles[i * 3 + 1];
    } else {
      total_bottles -= bottles[i * 3 + 2];
    }
  }
  return total_bottles;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ostringstream oss;

  const vector<string> orders({"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"});
  vector<int> bottles;
  int num_bottles;
  while (cin >> num_bottles) {
    bottles.push_back(num_bottles);
    int total_bottles = num_bottles;
    for (size_t i = 1; i < kNumBottles; i++) {
      cin >> num_bottles;
      bottles.push_back(num_bottles);
      total_bottles += num_bottles;
    }

    int min_moves = INT_MAX;
    string min_order = "";
    for (size_t i = 0; i < orders.size(); i++) {
      int total_moves = GetTotalMoves(total_bottles, orders[i], bottles);
      if (total_moves < min_moves) {
        min_moves = total_moves;
        min_order = orders[i];
      }
    }
    oss << min_order << " " << min_moves << endl;
    bottles.clear();
  }
  cout << oss.str();
  return 0;
}
