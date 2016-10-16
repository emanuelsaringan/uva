#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class UnionFind {
 public:
   UnionFind(char max_char) {
     for (char c = 'A'; c <= max_char; c++) {
       data_[c] = c;
     }
   }

   void Union(char a, char b) {
     char a_root = Find(a);
     char b_root = Find(b);
     if (a_root != b_root) {
       for (auto& p : data_) {
         if (p.second == a_root) {
           p.second = b_root;
         }
       }
     }
   }

   char Find(char c) {
     char cur = c;
     while (data_[cur] != cur) {
       cur = data_[cur];
     }
     return cur;
   }

   int CountComponents() {
     unordered_set<char> unique_chars;
     for (const pair<char, char>& p : data_) {
       unique_chars.insert(p.second);
     }
     return unique_chars.size();
   }
 
 private:
   unordered_map<char, char> data_;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int cases;
  string line;
  getline(cin, line);
  cases = stoi(line);
  getline(cin, line);  // garbage.
  while (cases--) {
    getline(cin, line);
    char max_node = line[0];
    UnionFind uf(max_node);
    getline(cin, line);
    while (!line.empty()) {
      char src = line[0];
      char dest = line[1];
      uf.Union(src, dest);
      getline(cin, line);
    }
    cout << uf.CountComponents() << '\n';
    if (cases > 0) {
      cout << '\n';
    }
  }
  return 0;
}
