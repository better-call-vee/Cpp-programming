#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int studentid;
    int age;

    Student ()
    {

    }

    Student (string s, int id, int roll)
    {
        name = s;
        studentid = id;
        age = roll;
    }

    void print_info ()
    {
        cout<<name<<" "<<studentid<<" "<<age<<" "<<fathersname<<" "<<mothersname<<"\n";
    }

    bool operator < (Student s)
    { //it's operator overloading. comparing the class with another similar class
        //which is included in the main function
        return studentid < s.studentid;
    }
};


//bool comp(Student a, Student b)
//{
//    //when a is less than b??
//    return a.studentid < b.studentid; //if a is smaller than b, it will
//    //return true, else it'll return false
//}
//then we have to write another parameter in sort function which is 'comp'
int main ()
{
    vector<Student>a;
    for(int i=0; i<10; i++)
    {
        a.push_back(Student("A", 20-i, 20));
    }

    for(int i=0; i<10; i++)
    {
        a[i].print_info();
    }

    cout<<"\n\n"<<"After Sorting ascendingly: \n";
    sort(a.begin(), a.end());
    for(int i=0; i<10; i++)
    {
        a[i].print_info();
    }


    return 0;
}
