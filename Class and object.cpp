#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string name;
    int studentid;
    int age;
    string fathersname;
    string mothersname;

    void print_info () {
        cout<<name<<" "<<studentid<<" "<<age<<" "<<fathersname<<" "<<mothersname<<"\n";
    }
};

class Rectangle {
public:
    int width, height;
    Student s2; //we can also use class in another class
    int calculate_area() {
        return height*width; //declaring function inside a class because function needs those objects
    }
    int calculate_peri() {
        return 2*(height+width);
    }
};

//recursive type class
class Person {
public:
    string name;
    Person *father, *mother; //using pointer just to change in the particular address
    void print_informations() {
        cout<<"Name = "<<name<<"\n";
        cout<<"Father's name = "<<father->name<<"\n";
        cout<<"Mother's name = "<<mother->name<<"\n";
    }

};

int main () {
    //class is more likely similar to structure in C, creating ownself's variable
    Student s;
    s.name = "Tanvee";
    s.studentid = 1910464;
    s.age = 21;
    s.fathersname = "Tufan";
    s.mothersname = "Mily";
    s.print_info();

    Rectangle r1;
    r1.height = 4;
    r1.width = 8;
    r1.s2.name = "in rectangle";
    r1.s2.print_info();
    cout<<r1.calculate_area()<<"\n";
    cout<<r1.calculate_peri()<<"\n";

    Person *p = new Person;
    p->father = new Person;
    p->mother = new Person; //finally the pointers are pointed
    p->name = "A";
    p->father->name = "B";
    p->mother->name = "C";
    p->print_informations();
    delete p;
    return 0;
}
//The delete operator should only be used to destroy objects that were created
//dynamically using the 'new' operator.
//It is important to note that the object is created dynamically on the heap,
//which means that it will exist until it is explicitly destroyed using the
//delete operator. If you do not destroy the object when you are finished with it,
//it will remain in memory until the program ends, which can cause memory leaks and
//other issues.
