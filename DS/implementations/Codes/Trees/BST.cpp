#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T> *left, *right;

    Node(T val)
        : data(val), left(NULL), right(NULL) {}
};

template <typename T>
class BST {
private:
    Node<T> *root;

    Node<T>* insert(Node<T> *node, T key) {
        if (node == NULL)
            return new Node<T>(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);

        return node;
    }

    bool Search(T key,Node<T> *node){
        if (node == NULL){
            return false;
        }
        if (key < node->data){
            return Search(node->left, key);
        }
        else if (key > node->data){
            return Search(node->right, key);
        }
        return true;
    }
    
    Node<T>* inpre(Node<T> *node) {
        Node<T> *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node<T>* deleteNode(Node<T> *node, T key) {
        if (node == NULL)
            return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);

        else if (key > node->data)
            node->right = deleteNode(node->right, key);

        else {
            if (node->left == NULL) {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }

            Node<T> *temp = inpre(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    //another way of deletion
    // bool deleteNode(Node*& root, int key) {
    //     // find the node to be deleted
    //     if (root == nullptr) {
    //         return false;  // key not found
    //     } else if (key < root->key) {
    //         return deleteNode(root->left, key);
    //     } else if (key > root->key) {
    //         return deleteNode(root->right, key);
    //     }
    //     // delete the node
    //     if (root->left == nullptr && root->right == nullptr) {
    //         // case 1: node has no children
    //         delete root;
    //         root = nullptr;
    //     } else if (root->left == nullptr) {
    //         // case 2: node has one child (right)
    //         Node* temp = root;
    //         root = root->right;
    //         delete temp;
    //     } else if (root->right == nullptr) {
    //         // case 2: node has one child (left)
    //         Node* temp = root;
    //         root = root->left;
    //         delete temp;
    //     } else {
    //         // case 3: node has two children - replace with min from right subtree
    //         Node* minRight = root->right;
    //         while (minRight->left != nullptr) {
    //             minRight = minRight->left;
    //         }
    //         root->key = minRight->key;
    //         return deleteNode(root->right, minRight->key);
    //     }
    //     return true;  // deletion successful
    // }
    void printPRE(Node<T> *node) {
        if (node == NULL)
            return;

       
        std::cout << node->data << " ";
        printPRE(node->left);
        printPRE(node->right);
    }

public:
    BST() : root(NULL) {}

    void insert(T key) {
        root = insert(root, key);
    }

    void remove(T key) {
        root = deleteNode(root, key);
    }

    void print(Node<T> *node) {
        if (node == NULL)
            return;

        print(node->left);
        std::cout << node->data << " ";
        print(node->right);
    }

    void preOrder() {
        printPRE(root);
    }

    void printTree() {
        print(root);
    }
};

int main() {
    // BST<int> bst;
    // bst.insert(5);
    // bst.insert(3);
    // bst.insert(7);
    // bst.insert(1);
    // bst.insert(9);
    // // bst.insert(2);

    // bst.printTree(); // prints: 1 3 5 7 9

    // bst.remove(5);
    // std::cout<<std::endl;

    // bst.printTree(); // prints: 1 5 7 9
    BST<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    std::cout<<"the Tree: \n";
    tree.preOrder();
    tree.remove(30);
    tree.remove(40);
    std::cout<<"\nthe Tree: \n";
    tree.preOrder();
    return 0;
}
