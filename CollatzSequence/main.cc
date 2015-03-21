#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int case_num = 1;
  long A, L, cur_a;
  cin >> A >> L;
  while (A >= 0 || L >= 0) {
    cur_a = A;
    long num_terms = 1;
    while (cur_a != 1 && cur_a <= L) {
      if (cur_a % 2 == 0) {
        cur_a >>= 1;
      } else {
        cur_a = 3 * cur_a + 1;
      }
      num_terms++;
    }
    if (cur_a > L) {
      num_terms--;
    }
    printf("Case %d: A = %ld, limit = %ld, number of terms = %ld\n",
        case_num, A, L, num_terms);
    case_num++;
    cin >> A >> L;
  }
  return 0;
}
