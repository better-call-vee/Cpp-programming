#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int studentid;
    int age;
    string fathersname;
    string mothersname;

    //constructor is a kind of function which doesn't return anything, they
    //don't have a return type, not even void.
    Student (string name, int id, int ag, string f_name, string m_name)
    {
        //those parameters mean, the class won't be built without those.
        //if the parameter's name and class's name are the same. eg:
        this->name = name; //then we can write like this, otherwise we can't
        studentid = id;
        age = ag;
        fathersname = f_name;
        mothersname = m_name;
    }

    Student (string s, int id, int roll)   //this is called constructor overload
    {
        name = s;
        studentid = id;
        age = roll;
    }

    void print_info ()
    {
        cout<<name<<" "<<studentid<<" "<<age<<" "<<fathersname<<" "<<mothersname<<"\n";
    }

};

class Person
{
public:
    string name;
    Person *father, *mother;

    Person ()
    {
        father = NULL; //means they don't point to anyone
        mother = NULL;
    }

    Person(string name, string f_name, string m_name)
    {
        this->name = name;
        father = new Person;
        father->name = f_name;
        mother = new Person;
        mother->name = m_name;
    }

    void print_informations()
    {
        cout<<"Name = "<<name<<"\n";
        cout<<"Father's name = "<<father->name<<"\n";
        cout<<"Mother's name = "<<mother->name<<"\n";
    }

    ~Person()
    {
        cout<<"Called\n"; //destructor
        if(father != NULL) //else it will be trapped in recursion
            delete father;
        if(mother != NULL)
            delete mother;
    }

};

int main ()
{

    Student s("A", 10, 20, "B", "C"); //that's how  you can call a constructor.
    s.print_info();

    Student s2("OVERLOAD", 13, 43);
    s2.print_info();

    //BUT, if you do this:
    //Student s3; it will give error.it won't give error if there was a
    //constructor in the class like this -> Student () {}

    Person p("A", "B", "C");
    p.print_informations();

    return 0;
}
