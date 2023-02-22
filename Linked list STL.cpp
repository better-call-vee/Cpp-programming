//this built in is basically for doubly linked list.

#include<bits/stdc++.h>
using namespace std;

//printing function
void print (list<int>l)
{
    //O(n)
    //list<int>::iterator a = l.begin();
    auto a = l.begin(); //starting from head
    while(a!=l.end()) //while is running until it's not equals to the nullptr.
    {
        cout<<*a<<" ";
        a++;
    }
    cout<<"\n";
}

void Insert(list<int>&l, int index, int value) { //we should use reference here
    //(&l), otherwise a copy of l will be sent from the main function. and by
    //referencing, we are directly getting the address of l and working on it.
     //insert at any position.
    auto it = l.begin();//we have to do it by an iterator. so, we need to
    //set an iterator at head. O(1)
    advance(it, index);//we are going right by index steps, towards the given
    //index O(index)
    l.insert(it, value);//here we go. iterator takes that targetted address and
    //insert the value O(1)
    ///so, overall time complexity is O(n)
}

void Delete(list<int>&l, int index) {
    auto it = l.begin();
    advance(it, index);
    l.erase(it);
}

int main ()
{
    list<int>l;
    l.push_back(10);//insert at tail.
    l.push_back(12);
    l.push_front(33); //insert at head.
    //as it's dynamic, we can't traverse like array. we need to use iterator.
    //linked list is like a container. we can't access it through index.
    cout<<"Printing the linked list with the function: ";
//    for(auto it=l.begin(); it!=l.end(); it++)
//    {
//        cout<<*it<<" ";
//    }
    print(l);

    l.sort();
    cout<<"Sorting Ascendingly: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";
    }

    l.sort(greater<int>());
    cout<<"\nSorting Descendingly: ";
    for(auto it=l.begin(); it!=l.end(); it++)
    {
        cout<<*it<<" ";
    }

    cout<<"\nThe last element is "<<l.back()<<'\n';
    l.pop_front();
    //l.pop_back() will delete the last element
    cout<<"Now the front element is :"<<l.front()<<'\n';

    Insert(l, 2, 69);
    Insert(l, 2, 100);
    Insert(l, 1, 9);
    cout<<"After inserting with Insert function: ";
    print(l);
    Delete(l, 2);
    cout<<"After deleting with Delete function: ";
    print(l);
    cout<<"THE SIZE OF THE LINKED LIST: "<<l.size();

    return 0;
}
