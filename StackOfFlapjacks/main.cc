#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace {
  bool IsSorted(const vector<int>& pancakes) {
    for (int i = 1; i < pancakes.size(); i++) {
      if (pancakes[i - 1] < pancakes[i]) {
        return false;
      }
    }
    return true;
  }

  void Flip(vector<int>& pancakes, int index) {
    reverse(pancakes.begin() + index, pancakes.end());
  }

  int FindIndexOfMax(const vector<int>& pancakes, int start) {
    int index_of_max = start;
    for (int i = start + 1; i < pancakes.size(); i++) {
      if (pancakes[i] > pancakes[index_of_max]) {
        index_of_max = i;
      }
    }
    return index_of_max;
  }

  void PrintVector(const vector<int>& vec) {
    bool first = true;
    for (int v : vec) {
      if (first) {
        first = false;
      } else {
        cout << " ";
      }
      cout << v;
    }
    cout << endl;
  }
} // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string line;
  while (getline(cin, line)) {
    stringstream iss(line);
    istream_iterator<string> begin(iss);
    istream_iterator<string> end;
    vector<string> pancakes_str(begin, end);
    vector<int> pancakes;
    for (const string& s : pancakes_str) {
      pancakes.push_back(stoi(s));
    }
    PrintVector(pancakes);
    reverse(pancakes.begin(), pancakes.end());

    vector<int> result;
    int cur_pancake = 0;
    while (!IsSorted(pancakes)) {
      int index_of_max = FindIndexOfMax(pancakes, cur_pancake);
      if (cur_pancake != index_of_max) {
        if (index_of_max != pancakes.size() - 1) {
          Flip(pancakes, index_of_max);
          result.push_back(index_of_max + 1);
        }
        Flip(pancakes, cur_pancake);
        result.push_back(cur_pancake + 1);
      }
      cur_pancake++;
    }
    result.push_back(0);
    PrintVector(result);
  }
  return 0;
}
