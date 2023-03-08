//(0)A----B(1)
//       /\            [0, 1]
//      /  \           [1, 2]
//     /    \          [1, 3]
//    /      \         [2, 3]
//(2)C--------D(3)

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int nodes = 4;
    vector<vector<int>>edge_list;

    edge_list.push_back({0,1});  //O(E) , wcs = O(n^2)
    edge_list.push_back({1,2});
    edge_list.push_back({1,3});
    edge_list.push_back({2,3});

//    vector<vector<int>>edge_list =
//    {
//        {0,1},
//        {1,2},
//        {1,3},
//        {2,3}
//    };

    for(int i=0; i<edge_list.size(); i++)
    {
        cout<<edge_list[i][0]<<" "<<edge_list[i][1]<<endl; //first element [i][0]
        //is the first node of the edge pair. [i][1] is the second node of the
        //edge pair.
    }
    return 0;
}
