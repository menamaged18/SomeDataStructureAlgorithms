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

class BST {
private:

    class Node {
    public:
        int data;
        Students stu;
        Node *left, *right;

        Node(Students val)
            : stu(val), data(val.getID()), left(NULL), right(NULL) {}
    };

    Node* root;

    Node* insert(Node* node, Students key) {
        if (node == NULL){
            return new Node(key);
        }
        if (key.getID() < node->data){
            node->left = insert(node->left, key);
        }
        else if (key.getID() > node->data){
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node* Search(Node*node,int key){
        if (node == NULL){
            return node;
        }
        if (key < node->data){
            return Search(node->left, key);
        }
        else if (key > node->data){
            return Search(node->right, key);
        }
        return node;
    }

    // inorderpredecessor function used in delete function
    Node* inpre(Node *node) {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    // Node* deleteNode(Node *node, int data) {
    //     if(node == NULL){
    //         return node;
    //     }
    //     if(data < node->data){
    //         node->left = deleteNode(node->left,data);
    //     }else if (data > node->data){
    //         node->right = deleteNode(node->right,data);
    //     }else {
    //         if(node->left == NULL && node->right == NULL) {
    //             // node->stu.Print();
    //             delete node;
    //             node = NULL;
    //         }else if(node->left == NULL) {
    //             struct Node *temp = node;
    //             node = node->right;
    //             // temp->stu.Print();
    //             delete temp;
    //         }else if(node->right == NULL) {
    //             struct Node *temp = node;
    //             node = node->left;
    //             // temp->stu.Print();
    //             delete temp;
    //         }else {
    //             //if the node have left child and right child
    //             //find the most left node or in oher word the inorderpredecessor (right->mostleft) i used this one
    //             // or inorderSuccessor(left->mostright) 
    //             struct Node *temp = inpre(node->right);
    //             // node->stu.Print();
    //             node->data = temp->data;
    //             node->stu = temp->stu;
    //             node->right = deleteNode(node->right,temp->data);
    //         }
    //     }
    //     return node;
    // }

    Node* deleteNode(Node* node, int key) {
        if (node == NULL){
            return node;
        }
        if (key < node->data){
            node->left = deleteNode(node->left, key);
        }else if (key > node->data){
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
            node->data = temp->data;
            node->stu = temp->stu;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    //this function prints the tree in inorder way => (Left , Node , Right)
    void print(Node* node) {
        if (node == NULL){
            return;
        }
        print(node->left);
        node->stu.Print();
        print(node->right);
    }

public:
    BST() : root(NULL) {}

    void insert(Students key) {
        root = insert(root, key);
    }

    void remove(int key) {       
        root = deleteNode(root, key);
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

    void printTree() {
        print(root);
    }

};




void heapify(Students arr[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < n && arr[l].getGpa() < arr[max].getGpa())
    {
        max = l;
    }
    if (r < n && arr[r].getGpa() < arr[max].getGpa())
    {
        max = r;
    }

    if (max != i)
    {
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

void buildHeap(Students arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(Students arr[], int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void AddStudent(int index, Students arr[], Students student)
{
    arr[index++] = student;
    for (int i = index / 2 ; i >= 0; --i)
    {
        heapify(arr, index,i);
    }
}

void print(Students arr[], int n)
{
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].getID() << " " << arr[i].getName() << " " << arr[i].getGpa() << " " << arr[i].getDepartment() << endl;
    }
}


void heapifymin(Students arr[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if (l < n && arr[l].getGpa() > arr[max].getGpa())
    {
        max = l;
    }
    if (r < n && arr[r].getGpa() > arr[max].getGpa())
    {
        max = r;
    }

    if (max != i)
    {
        swap(arr[i], arr[max]);
        heapifymin(arr, n, max);
    }
}

void buildHeapmin(Students arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifymin(arr, n, i);
    }
}

void heapSortmin(Students arr[], int n)
{
    buildHeapmin(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapifymin(arr, i, 0);
    }
}

void AddStudentmin(int index, Students arr[], Students student)
{
    arr[index++] = student;
    for (int i = index / 2 ; i >= 0; --i)
    {
        heapifymin(arr, index,i);
    }
}

void printmin(Students arr[], int n)
{
    heapSortmin(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].getID() << " " << arr[i].getName() << " " << arr[i].getGpa() << " " << arr[i].getDepartment() << endl;
    }
}


