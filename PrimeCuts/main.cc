#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace {

bool IsPrime(int n) {
  // n is always odd.
  int limit = sqrt(n);
  for (int i = 3; i <= limit; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void PopulatePrimes(vector<int>* primes) {
  primes->push_back(1);
  primes->push_back(2);
  for (int i = 3; i < 1000; i += 2) {
    if (IsPrime(i)) {
      primes->push_back(i);
    }
  }
}

int FindEndIndex(const vector<int>& primes, int n) {
  for (int i = 0; i < primes.size(); i++) {
    if (primes[i] == n) {
      return i;
    } else if (primes[i] > n) {
      return i - 1;
    }
  }
  return primes.size() - 1;
}

}  // namespace

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<int> primes;
  PopulatePrimes(&primes);
  int n, c;
  while (cin >> n >> c) {
    int sublistSize = FindEndIndex(primes, n) + 1;
    int centerListSize = sublistSize % 2 == 0 ?  2 * c : 2 * c - 1;
    int start, end;
    if (sublistSize <= centerListSize) {
      start = 0;
      end = sublistSize - 1;
    } else {
      start = (sublistSize >> 1) - (sublistSize % 2 == 0 ? c : c - 1);
      end = start + centerListSize - 1;
    }
    cout << n << " " << c << ":";
    for (int i = start; i <= end; i++) {
      cout << " " << primes[i];
    }
    cout << endl << endl;
  }
  return 0;
}
