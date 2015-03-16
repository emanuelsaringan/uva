#include <iostream>
#include <sstream>

using namespace std;

unsigned int exp(unsigned int B, unsigned int P, unsigned int M) {
  if (P == 1) {
    return B % M;
  }
  if (P == 0) {
    return 1;
  }
  if (P % 2 == 1) {
    return ((B % M) * exp(B, P - 1, M)) % M;
  }
  unsigned int half = exp(B, P >> 1, M);
  return ((half % M) * (half % M)) % M;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ostringstream oss;

  unsigned int B, P, M;
  while (cin >> B >> P >> M) {
    oss << exp(B, P, M) << endl;
  }
  cout << oss.str();
  return 0;
}
