#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T, M;
  cin >> T;
  for (size_t i = 0; i < T; i++) {
    cin >> M;
    vector<tuple<string, int, int>> manufacturers(M);

    string name;
    int L, H;
    for (size_t j = 0; j < M; j++) {
      cin >> name >> L >> H;
      manufacturers[j] = make_tuple(name, L, H);
    }

    if (i != 0) {
      cout << endl;
    }

    int Q, q;
    cin >> Q;
    for (size_t j = 0; j < Q; j++) {
      cin >> q;
      string manufacturer = "";
      for (const tuple<string, int, int>& m : manufacturers) {
        if (get<1>(m) <= q && q <= get<2>(m)) {
          if (manufacturer.empty()) {
            manufacturer = get<0>(m);
          } else {
            manufacturer.clear();
            break;
          }
        }
      }
      cout << (manufacturer.empty() ? "UNDETERMINED" : manufacturer) << endl;
    }
  }
  return 0;
}
