#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int h, u, d, f;
  cin >> h >> u >> d >> f;
  while (h != 0) {
    double cur_height = 0;
    int cur_day = 0;
    double diff = 0.01 * f * u;
    while (true) {
      cur_height = cur_height + max(0.0, (u - cur_day * diff));
      if (cur_height > h) {
        cout << "success on day " << (cur_day + 1) << endl;
        break;
      }
      cur_height -= d;
      if (cur_height < 0) {
        cout << "failure on day " << (cur_day + 1) << endl;
        break;
      }
      cur_day++;
    }
    cin >> h >> u >> d >> f;
  }
  return 0;
}
