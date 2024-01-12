#include <iostream>

using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    BSTNode* root;

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        if (root == NULL) {
            root = new BSTNode(val);
            return;
        }

        BSTNode* curr = root;
        while (curr != NULL) {
            if (val < curr->data) {
                if (curr->left == NULL) {
                    curr->left = new BSTNode(val);
                    return;
                } else {
                    curr = curr->left;
                }
            } else if (val > curr->data) {
                if (curr->right == NULL) {
                    curr->right = new BSTNode(val);
                    return;
                } else {
                    curr = curr->right;
                }
            } else {
                // value already exists in the tree
                return;
            }
        }
    }

    bool search(int val) {
        BSTNode* curr = root;
        while (curr != NULL) {
            if (val < curr->data) {
                curr = curr->left;
            } else if (val > curr->data) {
                curr = curr->right;
            } else {
                return true; // value found
            }
        }
        return false; // value not found
    }
};

int main() {
    BST bst;

    // inserting values into the BST
    bst.insert(8);
    bst.insert(3);
    bst.insert(1);
    bst.insert(6);
    bst.insert(7);
    bst.insert(10);
    bst.insert(14);
    bst.insert(4);

    // searching for values in the BST
    cout << bst.search(6) << endl;  // output: 1 (true)
    cout << bst.search(11) << endl; // output: 0 (false)

    return 0;
}
