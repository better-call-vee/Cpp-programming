//Vector, Stack, Queue, Deque, Priority Queue, Set, Multiset, Map

//Set keeps all the elements in a sorted order and no duplicate value is present in
//it.
//Set => a {1,3,4,5}
//not Set => {1,1,2,3}/{2,3,4,6,5}
//let's create a set
//4 -> {4};
//2 -> {2,4};
//3 -> {2,3,4};
//5 -> {2,3,4,5};
//3 -> {2,3,4,5}; see, if we want to insert the same element, it won't be inserted.
///SET's PROPERTY => SORTED AND DISTINCT.

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    set<int>st;
    st.insert(5);
    st.insert(3);  //O(logn)
    st.insert(4);
    st.insert(7);
    st.insert(3);
    st.insert(4);

    cout<<"Printing the Set: ";
    for(auto i:st) //iterating on every element of the set sequentially.
    {
        cout<<i<<" ";  //O(n)
    }
    cout<<"\n";
    cout<<"The set has "<<st.size()<<" distinct numbers"<<"\n"; //O(1)

    cout<<"Printing with begin, end pointer iteration: ";
    for(auto it=st.begin(); it!=st.end(); it++)   //when the it will reach end
    {
        //element, our work is done. after the last element there is end();
        cout<<*it<<" ";    //O(n)
    }
    cout<<"\n";

    ///ERASE
    st.erase(5); //O(logn)
    cout<<"After erasing 5: ";
    for(auto i:st)
    {
        cout<<i<<" ";
    }
    cout<<"\n";

    ///FIND(Ologn)
    if(st.find(7) != st.end()) //if the value is present in the set, it will return
    //the value's memory address, else it will the return the address at last
    //where there's no value(end()).
    {
        cout<<"7 found\n";
    }
    else
    {
        cout<<"7 not found\n";
    }
    if(st.find(5) != st.end()) //it's returning st.end().
    {
        cout<<"5 found\n";
    }
    else
    {
        cout<<"5 not found\n";
    }
    return 0;
}
