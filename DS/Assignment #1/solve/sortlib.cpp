#include <bits/stdc++.h>
using namespace std;

//in selection sort we select the position then find the element
template <class T>
void SelectionSort(T arr[],int size){
    for (size_t i = 0; i < size; i++){
        int smallest = i;
        for (size_t j = i + 1; j < size; j++){
            if (arr[smallest] > arr[j]){
                smallest = j;
            }
        }
        swap(arr[smallest],arr[i]);
    }
}

template <class T>
void BubbleSort(T arr[],int size){
    // int flag; //to make it adaptive,
    //adaptive means that if it the array is sorted it will not loop in vain
    for (size_t i = 0; i < size; i++){
        // flag = 0;
        for (int j = 0; j < size - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                // flag = 1;
            }
        }
    }
}

template <class T>
void InsertionSort(T arr[],int size){
    for (size_t i = 1; i < size; i++){
        int x = arr[i];
        int j = i - 1;
        while (arr[j] > x && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}


//in quick sort we select an element then we find its position
int QSPartition(int arr[], int low, int high)
{
    int pivot = arr[high]; // my pivot is last element
    int i = (low - 1);// Index of smaller element and indicates
                    // the right position of pivot found so far
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}



void QuickSort(int arr[],int start,int end){
    if (start < end){
        int Nposition = QSPartition(arr,start,end);
        QuickSort(arr,start,Nposition-1);
        QuickSort(arr,Nposition+1,end);
    }
}


void merge(int arr[],int low,int mid, int high){
    int l = low , j = mid+1,k = low;
    int temp[high+1];
    while (l <=mid && j<high){
        if (arr[l] < arr[j]){
            temp[k++] = arr[l++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    for (;l <=mid;l++){
        temp[k++] = arr[l];
    }
    for (;j <high;j++){
        temp[k++] = arr[j];
    }
    for (size_t i = low; i < high; i++){
        arr[i] = temp[i];
    }
}

//to make MergeSort work send to high 9 if you 10 elements and so,on
void MergeSort(int arr[],int low , int high){
    int mid;
    if (low < high){
        mid = (low + high )/ 2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int findmax(int arr[],int size){
    int max = arr[0];
    for (size_t i = 1; i < size; i++){
        if (arr[i]> max){
            max = arr[i];
        }
    }
    return max;
}

void CountSort(int arr[],int size){
    int max = findmax(arr,size);
    int temp[max+1];
    for (size_t i = 0; i < max+1; i++){
        temp[i] = 0;
    }

    for (size_t i = 0; i < size; i++){
        temp[arr[i]]++;
    }
    int c = 0;
    for (size_t i = 0; i < max+1; i++){
        while(temp[i] > 0){
            arr[c++] = i;
            temp[i]--;
        }
    }
}

void ShellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}

struct Node
{
    int info{};
    Node* link{};
    Node* previous{};
};


void bucketSort(vector<double>& arr, int num_buckets) {
    // Create empty buckets
    vector<vector<double>> buckets(num_buckets);
    // Distribute elements into buckets based on their value
    for (double val : arr) {
        int index = val * num_buckets;
        buckets[index].push_back(val);
    }
    // Sort each bucket (using insertion sort)
    for (int i = 0; i < num_buckets; i++) {
        int j = 1;
        while (j < buckets[i].size()) {
            double key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
            j++;
        }
    }
    // Concatenate sorted buckets
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (double val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

int main(){
    int a[] ={3,4,1,7,2,5};
    ShellSort(a,6);
    for (size_t i = 0; i < 6; i++)
    {
        cout<<a[i]<<" ";
    }
}

