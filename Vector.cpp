#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> a; // at first, vector is declared with size 0
    for (int i = 0; i < 10; i++)
    {
        a.push_back(i); // now, the size will be changed dynamically, and it will
        // take elements as the loop goes on.
    }

    a.insert(a.begin() + 1, 100); // we are inserting 100 in the 2nd index
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\n";
    }
    a.erase(a.begin() + 1); // deletes the second element
    a.pop_back();           // deletes the last element
    cout << "\vAfter the deletion\n";
    for (int i = 0; i < a.size(); i++) // a.size means the size of vector a now
    {
        cout << a[i] << "\n";
    }

    // suppose, a vector:
    vector<int> b; // it's size is 0
    b.resize(10);  // we are resizing the vector with size 10. and now it will
    // allocate 10 zeroes in the vector. {0,0,0,0,0,0,0,0,0,0}

    vector<int> c = {1, 2, 3, 4, 5};
    c.resize(3);
    cout << "\vAfter resizing vector c to 3 elements" << endl;
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << endl;
    }

    vector<int> ph(1);
    ph[0] = 9;
    ph.resize(9);
    cout << ph.back() << '\n'; // back() indicates the last element of a vector

    return 0;
}

// vector can be initialized like this with size.
// vector<int>a(10);
// vector<int> v(5, 2); this sets the 5 sized vectors all elements to 2.
// v.front() will print 2. front means the very first element

/*
vector size function is an unsigned int.
an unsigned integer can only represent non-negative integers

#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  for (int i = 0; i < v.size() - 1; i++) { // use i < (int)v.size() - 1 here

  }
  return 0;
}

*/