#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T, N;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    vector<int> speeds(N);
    for (int j = 0; j < N; j++) {
      cin >> speeds[j];
    }
    cout << "Case " << (i + 1) << ": " <<
      *max_element(speeds.begin(), speeds.end()) << endl;
  }
  return 0;
}
