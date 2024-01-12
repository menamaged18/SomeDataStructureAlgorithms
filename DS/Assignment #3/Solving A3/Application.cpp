#include <iostream>
#include <fstream>
#include <string>
#include "Containers.cpp"
// #include "BST.cpp"
// #include "AVL.cpp"
// #include "MinHeap.cpp"
// #include "Students.cpp"
using namespace std;


class application{
private:
    void menu(){
        cout<<"Choose Data Structure: \n"
              "1. BST\n"
              "2. AVL\n"
              "3. Min Heap\n"
              "4. Max Heap\n"
              "5. Exit Program\n"
              "=> ";
    }

    void readFromFileBST(string filename,BST &student) {
        // Create an input file stream
        ifstream inputFile(filename);
        // Check if the file was opened successfully
        if (!inputFile.is_open()) {
            cout << "Unable to open file";
            return;
        }
        int numofObjects = 0;
        int id = 0;
        string name = "",Dep="";
        float GPA = 0.0;
        // Students *student;
        string line;
        // Read and output each line in the file
        for (int i = 1; getline(inputFile, line); i++) {
            // cout << "Line " << i << ": " << line << std::endl;
            if (i == 1){
                numofObjects = stoi(line); //convert line to int
            }else{
                if (i%4==2){   // i%4 = 2 => id line
                    id = stoi(line);
                    // student[id].SetID(id);
                }else if (i%4==3){ //i%4 ==3 => name line
                    name = line;
                    // student[id].Setname(name);
                }else if (i%4==0){ //i%4 ==4 => Gpa line 
                    GPA = stof(line);
                    // student[id].SetGPA(GPA);
                }else{   //else =>dep line
                    Dep = line;  
                    // student[id].SetDepartment(Dep);
                    Students x(id,name,GPA,Dep);
                    student.insert(x);
                } 
            }
        }
        // Close the file
        inputFile.close();
    }
    void readFromFileAVL(string filename,AVL &student) {
        // Create an input file stream
        ifstream inputFile(filename);
        // Check if the file was opened successfully
        if (!inputFile.is_open()) {
            cout << "Unable to open file";
            return;
        }
        int numofObjects = 0;
        int id = 0;
        string name = "",Dep="";
        float GPA = 0.0;
        // Students *student;
        string line;
        // Read and output each line in the file
        for (int i = 1; getline(inputFile, line); i++) {
            // cout << "Line " << i << ": " << line << std::endl;
            if (i == 1){
                numofObjects = stoi(line); //convert line to int
            }else{
                if (i%4==2){   // i%4 = 2 => id line
                    id = stoi(line);
                    // student[id].SetID(id);
                }else if (i%4==3){ //i%4 ==3 => name line
                    name = line;
                    // student[id].Setname(name);
                }else if (i%4==0){ //i%4 ==4 => Gpa line 
                    GPA = stof(line);
                    // student[id].SetGPA(GPA);
                }else{   //else =>dep line
                    Dep = line;  
                    // student[id].SetDepartment(Dep);
                    Students x(id,name,GPA,Dep);
                    student.insert(x);
                } 
            }
        }
        // Close the file
        inputFile.close();
    }
    
    
    //ways of store here...
    //BST Way
    BST bstContainer;
    //helper functions of BST
    void menu2(){
        cout<<"Choose one of the following options: \n"
              "1. Add student\n"
              "2. Remove student\n"
              "3. Search student\n"
              "4. Print All (sorted by id)\n"
              "5. Return to main menu\n"
              "=> ";
    }
    
    bool bstSearch(int x){
        Students student = bstContainer.StudentInformation(x);
        if (student.getID() != 0){
            cout<<"Student is found.\n";
            student.Print();
            return true;
        }else{
            cout<<"Student is not found."<<endl;
            return false;
        }
    }
    
    void BSTChoice(){
        while (true){
            int ch;
            menu2();
            cin>>ch;
            if (ch == 1){
                string name , Department;
                float GPA;
                int x;
                while (true){                                   
                    cout<<"ID: ";
                    cin>>x;
                    //don't forget to check id
                    if (bstContainer.Find(x)){
                        cout<<"Enter non Exisit id: "<<endl; 
                    }else{
                        break;
                    }
                }
                cout<<"Name: ";
                cin>>name;
                cout<<"GPA: ";
                cin>>GPA;
                cout<<"Department: ";
                cin>>Department;
                Students student(x,name,GPA,Department);
                bstContainer.insert(student);
            }else if (ch == 2){
                int x;
                cout<<"ID: ";
                cin>>x;
                if (bstSearch(x)){
                    bstContainer.remove(x);
                    cout<<"Student Removed."<<endl;
                }
            }else if (ch == 3){
                int x;
                cout<<"ID: ";
                cin>>x;
                bstSearch(x);
            }else if (ch == 4){
                bstContainer.printTree();
            }else{
                break;
            }
        }
    }
    
    //AVL Way
    AVL avlContainer;
    
    bool avlSearch(int x){
        Students student = avlContainer.StudentInformation(x);
        if (student.getID() != 0){
            cout<<"Student is found.\n";
            student.Print();
            return true;
        }else{
            cout<<"Student is not found."<<endl;
            return false;
        }
    }
    
    void AVLChoice(){
        while (true){
            int ch;
            menu();
            cin>>ch;
            if (ch == 1){
                string name , Department;
                float GPA;
                int x;
                cout<<"ID: ";
                cin>>x;
                while (true){                                   
                    cout<<"ID: ";
                    cin>>x;
                    //don't forget to check id
                    if (avlContainer.Find(x)){
                        cout<<"Enter non Exisit id: "<<endl; 
                    }else{
                        break;
                    }
                }
                cout<<"Name: ";
                //don't forget to read the whole line
                cin>>name;
                cout<<"GPA: ";
                cin>>GPA;
                cout<<"Department: ";
                cin>>Department;
                Students student(x,name,GPA,Department);
                avlContainer.insert(student);
            }else if (ch == 2){
                int x;
                cout<<"ID: ";
                cin>>x;
                if (avlSearch(x)){
                    avlContainer.remove(x);
                    cout<<"Student Removed."<<endl;
                }
            }else if (ch == 3){
                int x;
                cout<<"ID: ";
                cin>>x;
                avlSearch(x);
            }else if (ch == 4){
                avlContainer.PrintTree();
            }else{
                break;
            }
        }
    }


public:
    void Run(){
        while (true){
            int choice;
            menu();
            cin>>choice;
            if (choice == 1){
                readFromFileBST("InputFile.txt",bstContainer);
                BSTChoice();
            }else if(choice == 2){
                readFromFileAVL("InputFile.txt",avlContainer);
                AVLChoice();
            }else if(choice == 3){
                Students arr[100];
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
                        bool flag =0;
                        while (true){                                   
                            cout << "Enter student id: ";
                            cin >> id;
                            for (size_t i = 0; i < n; i++){
                                if (arr[i].getID()== id){
                                    cout<<"NON Valid: "<<endl;
                                    break;
                                }else{
                                    s.SetID(id);
                                    flag =1;
                                }
                            }
                            if (flag){
                                break;
                            }
                            
                        }
                        cout << "Enter student name: ";
                        cin >> name;
                        s.Setname(name);
                        cout << "Enter student GPA: ";
                        cin >> GPA;
                        s.SetGPA(GPA);
                        cout << "Enter student department: ";
                        cin >> Department;
                        s.SetDepartment(Department);
                        AddStudent(n++ , arr ,s);
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
            }else if(choice == 4){
                Students arr[100];
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
                // n = indx;
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
                        bool flag =0;
                        while (true){                                   
                            cout << "Enter student id: ";
                            cin >> id;
                            for (size_t i = 0; i < n; i++){
                                if (arr[i].getID()== id){
                                    cout<<"NON Valid: "<<endl;
                                    break;
                                }else{
                                    s.SetID(id);
                                    flag =1;
                                }
                            }
                            if (flag){
                                break;
                            }
                        }
                        cout << "Enter student name: ";
                        cin >> name;
                        s.Setname(name);
                        cout << "Enter student GPA: ";
                        cin >> GPA;
                        s.SetGPA(GPA);
                        cout << "Enter student department: ";
                        cin >> Department;
                        s.SetDepartment(Department);
                        AddStudentmin(n++ , arr ,s);
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
            }else if(choice == 5){
                return;
            }else{
                cout<<"Wrong Input Try again.\n"<<endl;
            }
        }
    }
};

int main(){
    application obj;
    obj.Run();
}
