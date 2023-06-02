//Multiset and set have the same property but Multiset allows duplicate elements.

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    multiset<int>a;

    //O(logn)
    a.insert(5);
    a.insert(7);
    a.insert(4);
    a.insert(3);
    a.insert(4);
    a.insert(7);

    cout<<"Printing the multiset: ";
    for(auto it:a) cout<<it<<" ";
    cout<<"\n";

    cout<<"Size of the multiset: "<<a.size()<<"\n";

    //O(logn) -> erase all occurance
    a.erase(4);
    cout<<"Printing the multiset after commanding a.erase(4): ";
    for(auto it:a) cout<<it<<" ";
    cout<<"\n";

    //suppose, we want to just erase one of them.
    ///erase a single occurance
    a.erase(a.find(7));
    //here a.find() is giving the memory address to erase and it's deleting that.
    //when executing this, we have to make sure that actually that value exists in
    //the multiset. otherwise, it will return end(), which will be responsible to
    //crash the whole multiset

    cout<<"Printing the multiset after commanding 'erase single occurance': ";
    for(auto it:a) cout<<it<<" ";
    cout<<"\n";

    ///THE find() function's mechanism is as same as set.

    return 0;
}
