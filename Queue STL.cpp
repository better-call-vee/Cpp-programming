#include<bits/stdc++.h>
using namespace std;
int main ()
{
    queue<int>q;
    q.push(5);
    q.push(10);
    q.push(15);

    cout<<"Queue size is now: "<<q.size()<<"\n";
    cout<<q.empty()<<"\n"; //it will return 0, which means false. q isn't empty
    //right now. so.

    cout<<q.front()<<"\n";

    q.pop();
    cout<<q.front()<<"\n";

    q.pop();
    cout<<q.front()<<"\n";
    q.pop();

    cout<<q.empty()<<"\n"; //it will return 1, which means true. q is empty right
    //now. so.
    printf("\n\n\n");
    queue<char>q2;
    q2.push('a');
    q2.push('b');
    q2.push('c');

    cout<<"CHAR Queue size is now: "<<q2.size()<<"\n";
    cout<<q2.empty()<<"\n"; //it will return 0, which means false. q isn't empty
    //right now. so.

    cout<<q2.front()<<"\n";

    q2.pop();
    cout<<q2.front()<<"\n";

    q2.pop();
    cout<<q2.front()<<"\n";
    q2.pop();

    cout<<q2.empty()<<"\n"; //it will return 1, which means true. q is empty right
    //now. so.
    return 0;
}
