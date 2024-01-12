#include <iostream>
#include "Students.cpp"
using namespace std;



class AVL
{
private:

    
    class Node {
    public:
        int key;
        int height;
        Students stu;
        Node *left, *right;

        Node(Students val)
            : stu(val), key(val.getID()), left(NULL), right(NULL),height(1) {}
    };

    Node *root;


    Node* Search(Node*node,int key){
        if (node == NULL){
            return node;
        }
        if (key < node->key){
            return Search(node->left, key);
        }
        else if (key > node->key){
            return Search(node->right, key);
        }
        return node;
    }

    //why this node? => to get the height even if the node is null it will return 0 
    int height(Node *node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node *node) {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node *p) {
        //p is the main node 
        //pleft is the left node of p 
        //plright is the right of the pleft node 
        /*
                 p                                   pleft
               /   \                                 /  \
            pleft  node      after rotation=>    node    p
            /    \                                     /   \
          node    plright                         plright   node
        */   
        Node *pleft = p->left;
        Node *plright = pleft->right;

        pleft->right = p;
        p->left = plright;

        p->height = max(height(p->left), height(p->right)) + 1;
        pleft->height = max(height(pleft->left), height(pleft->right)) + 1;

        return pleft;
    }

    Node* leftRotate(Node *p) {
        /*
                 p                                   pright
               /   \                                 /   \
            node   pRight      after rotation=>     p   node
                   /    \                         /  \
                 pRLeft  node                  node  pRLeft
        */   
        Node *pRight = p->right;
        Node *PRLeft = pRight->left;

        pRight->left = p;
        p->right = PRLeft;

        p->height = max(height(p->left), height(p->right)) + 1;
        pRight->height = max(height(pRight->left), height(pRight->right)) + 1;

        return pRight;
    }

    Node* insertNode(Node* node, Students key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key.getID() < node->key){
            node->left = insertNode(node->left, key);
        }
        else if (key.getID() > node->key){
            node->right = insertNode(node->right, key);
        } 
        // else{ // Equal keys are not allowed in BST  (If i deleted nothing will happen)
        //     return node;
        // }

        // Update the height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get the balance factor of this ancestor node to check whether this node became unbalanced
        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && key.getID() < node->left->key){
            return rightRotate(node);
        }
        // Right Right Case
        if (balanceFactor < -1 && key.getID() > node->right->key){
            return leftRotate(node);
        }
        // Left Right Case
        if (balanceFactor > 1 && key.getID() > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balanceFactor < -1 && key.getID() < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        // If the node is already balanced, return it
        return node;
    }

    // inorderpredecessor function used in delete function
    Node* inpre(Node *node) {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node *node, int key) {
        if (node == NULL){
            return node;
        }
        if (key < node->key){
            node->left = deleteNode(node->left, key);
        }else if (key > node->key){
            node->right = deleteNode(node->right, key);
        }else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            //if the node have left child and right child or no child
            //find the most left node or in oher word the inorderpredecessor (right->mostleft) i used this one
            // or inorderSuccessor(left->mostright)
            Node* temp = inpre(node->right);//node of 7 now
            node->key = temp->key;
            node->stu = temp->stu;
            node->right = deleteNode(node->right, temp->key);
        }

        // If the tree had only one node after deletion it will return
        if (node == NULL){
            return node;
        }
           
        // Update the height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get the balance factor of this ancestor node to check whether this node became unbalanced
        int balanceFactor = getBalanceFactor(node);

        // Left Left Case
        if (balanceFactor > 1 && key < node->left->key){
            return rightRotate(node);
        }
        // Right Right Case
        if (balanceFactor < -1 && key > node->right->key){
            return leftRotate(node);
        }
        // Left Right Case
        if (balanceFactor > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balanceFactor < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        // If the node is already balanced, return it
        return node;
    }

    void printInorder(Node* node) {
        if (node == NULL){
            return;
        }
        printInorder(node->left);
        cout << node->key << " ";
        printInorder(node->right);
    }

public:
    AVL(/* args */);

    void insert(Students key) {
        root = insertNode(root, key);
    }

    void remove(int key) {       
        root = deleteNode(root, key);
    }
    //not needed here 
    // void preOrderTraversal(Node *node) {
    //     if (node == NULL)
    //         return;
    //     cout << node->key << " ";
    //     preOrderTraversal(node->left);
    //     preOrderTraversal(node->right);
    // }

    // void preOrder() {
    //     preOrderTraversal(root);
    // }

    void PrintTree(){
        printInorder(root);
    }

    bool Find(int key) {       
        Node* isfound = Search(root,key);
        if (isfound != NULL){
            // cout<<"Student is found: ";
            // isfound->stu.Print();
            return true;
        }
        return false;
    }

    Students StudentInformation(int key){
        Node* isfound = Search(root,key);
        if (isfound != NULL){
            return isfound->stu;
        }
    }
    
    ~AVL();
};

AVL::AVL(/* args */)
{
    root = NULL;
}

AVL::~AVL()
{
}


// int main(){
//     AVL tree;
//     tree.insert(10);
//     tree.insert(20);
//     tree.insert(30);
//     tree.insert(40);
//     tree.insert(50);
//     tree.insert(25);
//     cout<<"the Tree: \n";
//     tree.PrintTree();
//     tree.remove(30);
//     tree.remove(40);
//     cout<<"\nthe Tree: \n";
//     tree.PrintTree();
// }

