
#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int studentid;
    int age;
    string fathersname;
    string mothersname;

    Student(string name, int studentid, int age) {
        this->name = name;
        this->studentid = studentid;
        this->age = age;
    }

    void print_info () {
        cout<<name<<" "<<studentid<<" "<<age<<" "<<fathersname<<" "<<mothersname<<"\n";
    }
};

int main () {
    Student *s = new Student("A", 10, 20);

    s->print_info();
    (*s).print_info();
    return 0;
}
