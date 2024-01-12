#include <iostream>
#include <fstream>
#include "Students.cpp"
using namespace std;

void heapify(Students arr[], int n, int i)
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
        heapify(arr, index, i);
    }
}
void print(Students arr[], int n)
{
    heapSort(arr, 10);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].getID() << " " << arr[i].getName() << " " << arr[i].getGpa() << " " << arr[i].getDepartment() << endl;
    }
}

int main()
{
    Students arr[100];
    // MinHeap mn;
    ifstream fs("InputFile.txt");
    int n, indx = 0;
    fs >> n;
    for (int i = 0; i < n; ++i)
    {
        string name, dep;
        float gpa;
        int id;
        fs >> id;
        fs.ignore();
        getline(fs, name);
        fs >> gpa >> dep;
        Students student(id, name, gpa, dep);
        arr[indx++] = student;
    }
    int choice;
    while (true)
    {
        cout << "Enter your choice:\n";
        cout << "1. Add Student\n";
        cout << "2. Print all\n";
        cout << "3. Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            int id;
            string name;
            float GPA;
            string Department;
            Students s;
            cout << "Enter student id: ";
            cin >> id;
            s.SetID(id);
            cout << "Enter student name: ";
            cin >> name;
            s.Setname(name);
            cout << "Enter student GPA: ";
            cin >> GPA;
            s.SetGPA(GPA);
            cout << "Enter student department: ";
            cin >> Department;
            s.SetDepartment(Department);
            AddStudent(n+1 , arr ,s);
        }
        else if (choice == 2)
        {
            print(arr, n);
        }
        else if (choice == 3)
        {
            break;
        }
    }
}
