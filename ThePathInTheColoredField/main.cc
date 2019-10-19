#include <bits/stdc++.h>

class point_t {
public:
  point_t(int32_t i, int32_t j)
    : i_(i), j_(j) {}

  uint32_t dist(const point_t& o) const {
    return std::abs(o.i_ - i_) + std::abs(o.j_ - j_);
  }

private:
  int32_t i_;
  int32_t j_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int32_t M;
  while (std::cin >> M) {
    std::vector<std::string> lines(M);
    for (int32_t i = 0u; i < M; ++i) {
      std::cin >> lines[i];
    }

    std::vector<point_t> ones;
    std::vector<point_t> threes;
    for (int32_t i = 0; i < M; ++i) {
      for (int32_t j = 0; j < M; ++j) {
        char val = lines[i][j];
        if (val == '1') {
          ones.emplace_back(i, j);
        } else if (val == '3') {
          threes.emplace_back(i, j);
        }
      }
    }

    uint32_t result = 0u;
    for (const point_t& o : ones) {
      uint32_t min_dist = std::numeric_limits<uint32_t>::max();
      for (const point_t& t : threes) {
        if (t.dist(o) < min_dist) {
          min_dist = t.dist(o);
        }
      }
      if (min_dist > result) {
        result = min_dist;
      }
    }
    std::cout << result << '\n';
  }
  return 0;
}
