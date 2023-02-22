#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string st = "abcdefghij";
    string:: iterator ite; //accessing the string. and it will traverse from start
    //to end.

    for(ite= st.begin(); ite!=st.end(); ite++)   //starting from the beginning element
    {
        //it's working as a pointer, for dereferencing, we need to use *. rbegin means
        //will start from the right side and it will be reversed
        cout<<*ite<<" ";
    }
    cout<<"\n";

//    string:: reverse_iterator rit;
//    for(rit = st.rbegin(); rit!=st.rend(); rit++) {
//        cout<<*rit<<" ";
//    }
    //there's another simple method for this. automatically recognizing if it's
    //reverse or straight
    for(auto ite=st.rbegin(); ite!=st.rend(); ite++)
    {
        cout<<*ite<<" ";
    }

    return 0;
}
