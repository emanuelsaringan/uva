#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n, m, case_num = 1;
  cin >> n;
  while (n != 0) {
    cout << "Case " << case_num++ << ":" << endl;
    vector<int> nums(n);
    for (size_t i = 0; i < n; i++) {
      cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cin >> m;
    for (size_t i = 0; i < m; i++) {
      int query;
      cin >> query;
      size_t left = 0;
      size_t right = nums.size() - 1;
      long cur_sum = nums[left] + nums[right];
      int min_diff = numeric_limits<int>::max();
      long closest_sum = cur_sum;
      while (cur_sum != query) {
        // Track closest sum.
        int diff = abs(cur_sum - query);
        if (diff < min_diff) {
          min_diff = diff;
          closest_sum = cur_sum;
        }
        // Try another pair.
        if (cur_sum > query) {
          right--;
        } else if (cur_sum < query) {
          left++;
        }
        // Pair must be distinct.
        if (left >= right) {
          break;
        }
        cur_sum = nums[left] + nums[right];
      }
      long result = (cur_sum == query) ? cur_sum : closest_sum;
      cout << "Closest sum to " << query << " is " << result << "." << endl;
    }
    cin >> n;
  }
  return 0;
}
