#include <iostream>
using namespace std;
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
        if (node == NULL){
            return new Node<T>(key);
        }
        if (key < node->data){
            node->left = insert(node->left, key);
        }
        else if (key > node->data){
            node->right = insert(node->right, key);
        }
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

    //inorderpredecessor function used in delete function
    Node<T>* inpre(Node<T> *node) {
        Node<T> *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node<T>* deleteNode(Node<T> *node, T key) {
        if (node == NULL){
            return node;
        }
        if (key < node->data){
            node->left = deleteNode(node->left, key);
        }else if (key > node->data){
            node->right = deleteNode(node->right, key);
        }else {
            if (node->left == NULL) {
                Node<T> *temp = node->right;
                delete node;
                return temp;
            }else if (node->right == NULL) {
                Node<T> *temp = node->left;
                delete node;
                return temp;
            }
            //if the node have left child and right child
            //find the most left node or in oher word the inorderpredecessor (right->mostleft) i used this one
            // or inorderSuccessor(left->mostright)
            Node<T> *temp = inpre(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    BST() : root(NULL) {}

    void insert(T key) {
        root = insert(root, key);
    }

    bool remove(T key) {
        root = deleteNode(root, key);
        if (Search(key,root)){
            return true;
        }
        return false;
    }
    //this function prints the tree in inorder way => (Left , Node , Right)
    void print(Node<T> *node) {
        if (node == NULL){
            return;
        }
        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }

    void printTree() {
        print(root);
    }
};

// int main() {
//     BST<int> bst;
//     bst.insert(5);
//     bst.insert(3);
//     bst.insert(7);
//     bst.insert(1);
//     bst.insert(9);
//     // bst.insert(2);

//     bst.printTree(); // prints: 1 3 5 7 9

//     bst.remove(5);
//     cout<<endl;

//     bst.printTree(); // prints: 1 3 7 9

//     return 0;
// }
