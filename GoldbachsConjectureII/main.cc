#include <math.h>
#include <iostream>
#include <set>
#include <vector>

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

bool FindPair(set<int>& primes, int n, int* removed) {
  for (set<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
    if (primes.find(n - *it) != primes.end()) {
      *removed = *it;
      primes.erase(it);
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

  int n;
  cin >> n;
  while (n != 0) {
    vector<int> removed;
    int to_remove;
    int num_pairs = 0;
    while (FindPair(primes, n, &to_remove)) {
      num_pairs++;
      removed.push_back(to_remove);
    }
    copy(removed.begin(), removed.end(), inserter(primes, primes.end()));
    cout << num_pairs << endl;
    cin >> n;
  }
  return 0;
}
