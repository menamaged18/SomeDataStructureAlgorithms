#include <iostream>
#include "Students.cpp"
using namespace std;


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

// void heapify(int arr[],int n,int i)
// {
//     int l=2*i+1;
//     int r=2*i+2;
//     int max=i;
//     if(l<n&&arr[l]>arr[max]){
//         max=l;
//     }
//     if(r<n&&arr[r]>arr[max]){
//         max=r;
//     }

//     if(max != i){
//         swap(arr[i],arr[max]);
//         heapify(arr,n,max);
//     }
// }

// void buildHeap(int arr[],int n)
// {
// 	for (int i = n / 2 - 1; i >= 0; i--){
//         heapify(arr, n, i);
//     }
// }

// void heapSort(int arr[], int n)
// {
// 	buildHeap(arr, n);
// 	for (int i = n-1; i >=0; i--)
// 	{
// 		swap(arr[0], arr[i]);
// 		heapify(arr, i, 0);
// 	}
// }

// void print(int arr[], int n)
// {
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// }

// int main(){
//     Students stu1(5,"Mina",3.0,"CS");
//     Students stu2(3,"Minaa",3.2,"AI");
//     Students stu3(7,"Minaa",3.2,"AI");
//     Students stu4(1,"Minaa",3.2,"AI");
//     Students stu5(9,"Minaa",3.2,"AI");
//     // BST<Students> stus;
//     // stus.insert(stu1);
//     // stus.insert(stu2);
//     // stus.printTree();
//     BST stus;
//     stus.insert(stu1);
//     stus.insert(stu2);
//     stus.insert(stu3);
//     stus.insert(stu4);
//     stus.insert(stu5);
//     stus.printTree();// prints: 1 3 5 7 9
//     if (stus.remove(5)){
//         cout<<"NODE is Found"<<endl;
//     }
    
//     cout<<endl;
//     stus.printTree();// prints: 1 3 7 9
// }



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
