#include <math.h>
#include <iostream>
#include <set>

using namespace std;

namespace {

bool IsPrime(int n) {
  if (n < 2) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  int limit = static_cast<int>(sqrt(n));
  for (int i = 3; i <= limit; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool FindPair(const set<int>& primes, int n, int* a, int* b) {
  for (int p : primes) {
    if (primes.find(n - p) != primes.end()) {
      *a = p;
      *b = n - p;
      return true;
    }
  }
  return false;
}

} // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  set<int> primes;
  primes.insert(2);
  for (int i = 3; i < 1000000; i += 2) {
    if (IsPrime(i)) {
      primes.insert(i);
    }
  }

  int n, a, b;
  cin >> n;
  while (n != 0) {
    if (FindPair(primes, n, &a, &b)) {
      cout << n << " = " << a << " + " << b << endl;
    } else {
      cout << "Goldbach's conjecture is wrong." << endl;
    }
    cin >> n;
  }
  return 0;
}
