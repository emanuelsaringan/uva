#include <math.h>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  double n, p;
  while (cin >> n >> p) {
    printf("%.0lf\n", pow(p, (1.0 / n)));
  }
  return 0;
}
