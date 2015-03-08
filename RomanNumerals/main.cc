#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

static const vector<string> ones(
    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"});
static const vector<string> tens(
    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"});
static const vector<string> hundreds(
    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"});
static const vector<string> thousands({"", "M", "MM", "MMM"});

bool IsArabic(string str, int* parsed_num) {
  try {
    *parsed_num = stoi(str);
    return true;
  } catch (...) {
    // Do nothing.
  }
  return false;
}

string ToRoman(int number) {
  return thousands[number / 1000] + hundreds[(number / 100) % 10] +
      tens[(number / 10) % 10] + ones[number % 10];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ostringstream oss;

  // Initialize Roman -> Arabic mapping.
  unordered_map<string, int> roman_arabic;
  for (size_t i = 1; i < 4000; i++) {
    roman_arabic[ToRoman(i)] = i;
  }

  string input;
  int parsed_num;
  while (cin >> input) {
    if (IsArabic(input, &parsed_num)) {
      oss << ToRoman(parsed_num) << endl;
    } else {
      oss << roman_arabic[input] << endl;
    }
  }
  cout << oss.str();
  return 0;
}
