#include<bits/stdc++.h>
using namespace std;

class Student
{
private:  //it's just only private outside, not inside
    string name;
    int studentid;
    int age;
public: //through public, we can access any modifier
    string fathersname;
    string mothersname;

    void print_info ()
    {
        cout<<name<<" "<<studentid<<" "<<age<<" "<<fathersname<<" "<<mothersname<<"\n";
    }
    void setinfo (string s, int id, int ag) {
        name = s;
        studentid = id;
        age = ag;
    }
};

///PROTECTED CLASS
class User {
protected:
    string namo;
    int aige;
};

class Admin: User {  //for protected access modifier, you have to inherit the class
private:
    string designation;
public:
    void Set(string s, int ag, string dg) {
        namo = s;
        aige = ag;
        designation = dg;
    }
    void print() {
        cout<<namo<<"\n"<<aige<<"\n"<<designation;
    }
};


int main ()
{
    Student s;
//    s.name = "Tanvee"; //it will show error now
//    s.studentid = 1910464;
//    s.age = 21;
//but if:
    s.setinfo("Private class accessing", 1910464, 21);
    s.fathersname = "Tufan";
    s.mothersname = "Mily";
    s.print_info();
    cout<<"\n\n"<<"NOW:"<<"\n";
    Admin ad;
    ad.Set("Protected class", 23, "009");
    ad.print();
    return 0;
}
