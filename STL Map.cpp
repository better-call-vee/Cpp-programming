//{key,value}
//map is like a pair.
//set{1,3,4,5} , suppose these are the keys
//Map{{1,10}, {3,20}, {4,30}, {5,40}}. Every key has to be distinct.
//map[4] will return 30

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    map<string, int>mp; //key is string, value is int.
    mp["goru"] = 1;
    mp["chagol"] = 2; //{{goru,1}, {chagol,2}, {vera,3}}
    mp["vera"] = 3;

    //Value of a key
    cout<<mp["goru"]<<"\n"; //map's like an array but with volitional indexing
    cout<<mp["vera"]<<"\n";

    //in map, the keys will be distinct but not necessarily the values will be
    //distinct.

    mp["cat"] = 2;
    cout<<"cat's value now: "<<mp["cat"]<<"\n";
    mp["cat"] = 5;
    cout<<"cat's value after being overwritten: "<<mp["cat"]<<"\n";

    //these all have O(logn) complexity. (insert/accessing)

    for(int i=0; i<3; i++)
    {
        string inp;
        cin>>inp;          //inserting elements into map.
        mp.emplace(inp, i); //mp.insert(make_pair(inp,i)); can be written like this
    }

    ///PRINT THE MAP O(n)
    cout<<"PRINTING THE MAP: \n";
    for(auto it:mp)
    {
        cout<<"Key : "<<it.first<<" , Value : "<<it.second<<"\n";
    }
    //map keeps the keys sorted. here the keys will be remained sorted
    //lexicographically.

    cout<<"\nThe map's size is = "<<mp.size()<<"\n"; //O(1)
    return 0;
}
