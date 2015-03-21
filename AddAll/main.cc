#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned long long total, a, b;
  int n, num;
  cin >> n;
  while (n != 0) {
    priority_queue<int, vector<int>, greater<int>> nums;
    total = 0;
    for (int i = 0; i < n; i++) {
      cin >> num;
      nums.push(num);
    }
    while (nums.size() != 1) {
      a = nums.top();
      nums.pop();
      b = nums.top();
      nums.pop();
      total += (a + b);
      nums.push(a + b);
    }
    cout << total << endl;
    cin >> n;
  }
  return 0;
}
