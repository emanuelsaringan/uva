#include <bits/stdc++.h>

namespace {

template<typename T>
bool check_helper(const std::vector<T>& v,
                  typename std::vector<T>::const_iterator i,
                  T target) {
  if (target == 0) return true;
  if (i == v.cend()) return false;
  if (*i > target) return false;
  return check_helper(v, i + 1, static_cast<T>(target - *i)) or check_helper(v, i + 1, target);
}

template<typename T>
bool check(const std::vector<T>& v, T target) {
  assert(not v.empty());
  return check_helper(v, v.cbegin(), target);
}

}  // namespace

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  uint16_t t, n, p;

  std::cin >> t;
  for (uint16_t ti = 0u; ti < t; ++ti) {
    std::cin >> n >> p;
    std::vector<uint16_t> bars;
    for (uint16_t pi = 0u; pi < p; ++pi) {
      uint16_t length;
      std::cin >> length;
      bars.push_back(length);
    }
    std::sort(bars.begin(), bars.end());
    std::cout << (check(bars, n) ? "YES" : "NO") << '\n';
  }
  return 0;
}
