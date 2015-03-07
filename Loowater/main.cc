#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const string kDoomedMessage = "Loowater is doomed!";

  long head, height;
  vector<long> heads, heights;
  int n, m;
  while ((cin >> n >> m) && (n != 0 || m != 0)) {
    for (size_t i = 0; i < n; i++) {
      cin >> head;
      heads.push_back(head);
    }
    for (size_t i = 0; i < m; i++) {
      cin >> height;
      heights.push_back(height);
    }

    if (n > m) {
      cout << kDoomedMessage << endl;
      continue;
    }

    sort(heads.begin(), heads.end());
    sort(heights.begin(), heights.end());

    unsigned long long total = 0L;
    size_t j = 0;
    bool failed = false;
    for (size_t i = 0; i < n; i++) {
      while (j < m && heads[i] > heights[j]) {
        j++;
      }
      if (j >= m) {
        failed = true;
        break;
      }
      total += heights[j];
      j++;
    }

    if (failed) {
      cout << kDoomedMessage << endl;
    } else {
      cout << total << endl;
    }

    heads.clear();
    heights.clear();
  }
  return 0;
}
