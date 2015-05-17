#include <math.h>
#include <iostream>
#include <unordered_set>

using namespace std;

namespace {
  bool IsPrime(int n) {
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

  void ComputePrimes(int upto, unordered_set<int>* primes) {
    for (int i = 2; i <= upto; i++) {
      if (IsPrime(i)) {
        primes->insert(i);
      }
    }
  }

  long ModPow(long a, long n) {
    a = a % n;
    long res = 1;
    for (int i = 0; i < n; i++) {
      res = (res * a) % n;
    }
    return res;
  }

  bool PassesCarmichaelTest(long n) {
    for (long a = 2; a < n; a++) {
      if (ModPow(a, n) != a) {
        return false;
      }
    }
    return true;
  }

  bool IsCarmichael(long n, const unordered_set<int>& primes) {
    return primes.find(n) == primes.end() && PassesCarmichaelTest(n);
  }
} // namespace

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // unordered_set<int> primes;
  // ComputePrimes(64999, &primes);
  // for (long i = 41041; i < 65000; i++) {
  //   if (IsCarmichael(i, primes)) {
  //     cout << "carmichaels.insert(" << i << ");" << endl;
  //   }
  // }

  unordered_set<int> carmichaels;
  carmichaels.insert(561);
  carmichaels.insert(1105);
  carmichaels.insert(1729);
  carmichaels.insert(2465);
  carmichaels.insert(2821);
  carmichaels.insert(6601);
  carmichaels.insert(8911);
  carmichaels.insert(10585);
  carmichaels.insert(15841);
  carmichaels.insert(29341);
  carmichaels.insert(41041);
  carmichaels.insert(46657);
  carmichaels.insert(52633);
  carmichaels.insert(62745);
  carmichaels.insert(63973);

  int n;
  cin >> n;
  while (n != 0) {
    if (carmichaels.find(n) != carmichaels.end()) {
      cout << "The number " << n << " is a Carmichael number." << endl;
    } else {
      cout << n << " is normal." << endl;
    }
    cin >> n;
  }
  return 0;
}

