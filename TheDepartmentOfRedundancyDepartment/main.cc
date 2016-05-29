#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  vector<int> nums;
  unordered_map<int, int> tally;
  int n;
  while (cin >> n) {
    if (tally.find(n) == tally.end()) {
      tally[n] = 1;
      nums.push_back(n);
    } else {
      tally[n]++;
    }
  }
  for (int nums_i : nums) {
    cout << nums_i << " " << tally[nums_i] << endl;
  }
  return 0;
}
