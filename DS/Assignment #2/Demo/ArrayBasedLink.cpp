#include <iostream>
using namespace std;

template <typename T>
class ArrayBasedLink
{
private:
    T * list;
    int Length;
    int MaxSize;
public:
    ArrayBasedLink(int size);
    void insertAt(T element, int index);
    void insertEnd(T element);
    int retrieveAt(int index);
    void removeAt(int index);
    void replaceAt (T newElement, int index);
    bool isItemAtEqual(T element, int index);
    bool isEmpty();
    bool isFull();
    int listSize(); 
    int maxListSize();
    void clear(); 
    void print();
    ~ArrayBasedLink();
};
template <typename T>
ArrayBasedLink<T>::ArrayBasedLink(int size){
    if (size<0){
        cout<<"Sorry invalid size.\n crating array of size 100."<<endl;
        MaxSize = 100;
    }else{
        MaxSize = size;
    }        
    Length = 0;
    list = new int[MaxSize];
}
template <typename T>
void ArrayBasedLink<T>::insertAt(T element,int index){
    if (MaxSize == Length){
        cout<<"Sorry Cannot insert that element because it's max size"<<endl;
        return;
    }
    if (index > MaxSize || index < 0){
        cout<<"Wrong index"<<endl;
        return;
    }
    for (int i = Length; i > index; i--){
        list[i] = list[i-1];
    }
    list[index] = element;
    Length++;
}
template <typename T>
void ArrayBasedLink<T>::insertEnd(T element){
    if (MaxSize == Length){
        cout<<"Sorry Cannot insert that element because it's max size"<<endl;
        return;
    }
    list[Length] = element;
    Length++;
}
template <typename T>
int ArrayBasedLink<T>::retrieveAt(int index) {
    if (index < 0 || index >= Length) {
        cout << "Error: Index out of range." << endl;
        return int();
    }
    return list[index];
}
template <typename T>
void ArrayBasedLink<T>::removeAt(int index){
    if (index > MaxSize || index < 0){
        cout<<"Wrong index"<<endl;
        return;
    }
    for (int i = index; i < MaxSize; i++){
        list[i] = list[i+1];
    }
    Length--;
}
template <typename T>
void ArrayBasedLink<T>::replaceAt(T newElement, int index){
    if (index > MaxSize || index < 0){
        cout<<"Wrong index"<<endl;
        return;
    }
    list[index] = newElement;
}
template <typename T>
bool ArrayBasedLink<T>::isItemAtEqual(T element,int index){
    return (element == list[index]);
}
template <typename T>
bool ArrayBasedLink<T>::isEmpty(){
    return (Length == 0);
}
template <typename T>
bool ArrayBasedLink<T>::isFull(){
    return (Length == MaxSize);
}
template <typename T>
int ArrayBasedLink<T>::listSize(){
    return Length;
}
template <typename T>
int ArrayBasedLink<T>::maxListSize(){
    return MaxSize;
}
template <typename T>
void ArrayBasedLink<T>::clear(){
    Length = 0;
}
template <typename T>
void ArrayBasedLink<T>::print(){
    for (int i = 0; i < Length; i++){
        cout<<list[i]<<" ";
    }
    cout<<endl;
}
template <typename T>
ArrayBasedLink<T>::~ArrayBasedLink()
{
    delete list;
}

int main(){

}
