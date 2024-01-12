#include <iostream>
#include <string>
using namespace std;

class Students
{
private:
    int id;
    string name;
    float GPA;
    string Department;

public:
    Students();
    Students(int ID, string Name, float Gpa, string Dep);
    Students(Students &s);
    void SetID(int _id);
    void Setname(string Name);
    void SetGPA(float Gpa);
    void SetDepartment(string Dep);
    int getID();
    string getName();
    string getDepartment();
    float getGpa();
    void Print();
    ~Students();
    friend void swap(Students &s1, Students &s2);
};

Students::Students()
{
    id = 0;
    name = "none";
    GPA = 0;
    Department = "none";
}

Students::Students(int ID, string Name, float Gpa, string Dep)
{
    id = ID;
    name = Name;
    GPA = Gpa;
    Department = Dep;
}

Students::Students(Students &s)
{
    id = s.getID();
    name = s.getName();
    GPA = s.getGpa();
    Department = s.getDepartment();
}

void Students::SetID(int _id)
{
    id = _id;
}

void Students::Setname(string Name)
{
    name = Name;
}

void Students::SetGPA(float Gpa)
{
    GPA = Gpa;
}

void Students::SetDepartment(string Dep)
{
    Department = Dep;
}

int Students::getID()
{
    return id;
}

string Students::getName()
{
    return name;
}

string Students::getDepartment()
{
    return Department;
}

float Students::getGpa()
{
    return GPA;
}

void Students::Print()
{
    cout << "[" << id << ", " << name << ", " << GPA << ", " << Department << "]" << endl;
}

Students::~Students()
{
}

void swap(Students &s1, Students &s2)
{
    swap(s1.id, s2.id);
    swap(s1.name, s2.name);
    swap(s1.GPA, s2.GPA);
    swap(s1.Department, s2.Department);
}
