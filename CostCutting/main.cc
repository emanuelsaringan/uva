#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  size_t cases;
  int s;
  vector<int> salaries;
  cin >> cases;
  for (size_t c = 0; c < cases; c++) {
    salaries.clear();
    for (int i = 0; i < 3; i++) {
      cin >> s;
      salaries.push_back(s);
    }
    sort(salaries.begin(), salaries.end());
    printf("Case %ld: %d\n", c + 1, salaries[1]);
  }
  return 0;
}
