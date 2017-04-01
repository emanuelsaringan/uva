#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t k;
  bool first = true;
  cin >> k;
  while (k != 0) {
    if (first) {
      first = false;
    } else {
      cout << '\n';
    }
    vector<int> S(k);
    for (size_t i = 0; i < k; i++) {
      cin >> S[i];
    }
    sort(S.begin(), S.end());
    for (size_t a = 0; a <= k - 6; a++) {
      for (size_t b = a + 1; b <= k - 5; b++) {
        for (size_t c = b + 1; c <= k - 4; c++) {
          for (size_t d = c + 1; d <= k - 3; d++) {
            for (size_t e = d + 1; e <= k - 2; e++) {
              for (size_t f = e + 1; f <= k - 1; f++) {
                cout << S[a] << ' ' << S[b] << ' ' << S[c] << ' ' << S[d] << ' '
                     << S[e] << ' ' << S[f] << '\n';
              }
            }
          }
        }
      }
    }
    cin >> k;
  }
  return 0;
}
