#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t num_books;
  int money;
  while (cin >> num_books) {
    vector<int> prices(num_books);
    for (size_t i = 0; i < num_books; i++) {
      cin >> prices[i];
    }
    cin >> money;
    sort(prices.begin(), prices.end());
    int l = 0, r = prices.size() - 1;
    int price_low, price_high;
    while (l < r) {
      int sum = prices[l] + prices[r];
      if (sum < money) {
        l++;
      } else if (sum > money) {
        r--;
      } else {
        price_low = prices[l++];
        price_high = prices[r--];
      }
    }
    cout << "Peter should buy books whose prices are " << price_low
         << " and " << price_high << ".\n\n";
  }
  return 0;
}
