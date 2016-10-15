#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  Node(char v) : value(v) {}

  char value;
  Node* left = nullptr;
  Node* right = nullptr;
};

class BinaryTree {
 public:
  void insert(char c, const unordered_map<char, int>& inorder) {
    if (root_ == nullptr) {
      root_ = new Node(c);
    } else {
      insert(root_, c, inorder);
    }
  }

  void postorder() {
    postorder(root_);
  }

 private:
  void insert(Node* node, char c, const unordered_map<char, int>& inorder) {
    if (inorder.at(c) < inorder.at(node->value)) {
      if (node->left == nullptr) {
        node->left = new Node(c);
      } else {
        insert(node->left, c, inorder);
      }
    } else {
      if (node->right == nullptr) {
        node->right = new Node(c);
      } else {
        insert(node->right, c, inorder);
      }
    }
  }

  void postorder(Node* node) {
    if (node == nullptr) {
      return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->value;
  }

  Node* root_ = nullptr;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int C;
  cin >> C;
  while (C--) {
    int N;
    cin >> N;
    string sequence;
    cin >> sequence;
    vector<char> preorder(N);
    for (size_t i = 0; i < sequence.length(); i++) {
      preorder[i] = sequence[i];
    }
    cin >> sequence;
    unordered_map<char, int> inorder;
    for (size_t i = 0; i < sequence.length(); i++) {
      inorder[sequence[i]] = i;
    }
    BinaryTree tree;
    for (char c : preorder) {
      tree.insert(c, inorder);
    }
    tree.postorder();
    cout << '\n';
  }
  return 0;
}
