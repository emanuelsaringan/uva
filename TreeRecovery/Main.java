import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BST bst = new BST();
        while (in.hasNext()) {
            String preorder = in.next();
            String inorder = in.next();

            for (int i = 0; i < preorder.length(); i++) {
                bst.insert(preorder.substring(i, i + 1), inorder);
            }

            bst.postorder();
            System.out.println();
            bst.clear();
        }
    }
}

class BST {
    Node root = null;

    public void insert(String value, String inorder) {
        if (this.root == null) {
            this.root = new Node(value);
        } else {
            insert(this.root, value, inorder);
        }
    }

    private void insert(Node root, String value, String inorder) {
        int valueIndex = inorder.indexOf(value);
        int rootIndex = inorder.indexOf(root.value);

        if (rootIndex < valueIndex) {
            if (root.right == null) {
                root.right = new Node(value);
            } else {
                insert(root.right, value, inorder);
            }
        } else {
            if (root.left == null) {
                root.left = new Node(value);
            } else {
                insert(root.left, value, inorder);
            }
        }
    }

    public void postorder() {
        postorder(root);
    }

    private void postorder(Node root) {
        if (root == null) {
            return;
        }

        postorder(root.left);
        postorder(root.right);
        System.out.print(root.value);
    }

    public void clear() {
        this.root = null;
    }
}

class Node {
    Node left = null;
    Node right = null;
    String value = null;

    public Node(String value) {
        this.value = value;
    }
}
