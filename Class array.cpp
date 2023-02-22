#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int studentid;
    int age;
    string fathersname;
    string mothersname;

    Student () {
                        //empty constructor is a must here
    }

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

    int a[10];
    Student s[10]; //10 objects have been created, but we need their constructor to
    //initialize them. for this , empty constructor is a must
    for(int i=0; i<10; i++) {
        s[i] = Student("A", i, 20);
    }
    for(int i=0; i<10; i++) {
        s[i].print_info();
    }

    return 0;
}
