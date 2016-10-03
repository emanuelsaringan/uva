#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  double N;
  cin >> N;
  while (N != 0) {
    int n = ceil(sqrt(N));
    int mid = pow(n, 2) - (n - 1);
    int x, y;
    if (n % 2 == 0) {
      if (N < mid) {
        x = N - pow(n - 1, 2);
        y = n;
      } else {
        x = n;
        y = n - (N - mid);
      }
    } else {
      if (N < mid) {
        x = n;
        y = N - pow(n - 1, 2);
      } else {
        x = n - (N - mid);
        y = n;
      }
    }
    cout << x << " " << y << '\n';
    cin >> N;
  }
  return 0;
}
