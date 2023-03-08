//(0)A----B(1)
//     3 /\
//      /  \
//    5/    \4
//    /  7   \
//(2)C--------D(3)
//0->1
//1->0,2,3
//2->1,3
//3->1,2
//same way implementation for directed and weighted graph. already have been
//discussed in the theory file.

#include<bits/stdc++.h>
using namespace std;

int main ()
{

    int nodes = 4;
    vector<int>adj_list[nodes];
    vector<pair<int, int>>adjwlist[3]; //this is for weighted list

    adj_list[0] = {1};    //O(E)/O(n^2) space complexity. same concept like Adj mat
    adj_list[1] = {0, 2, 3};
    adj_list[2] = {1, 3};
    adj_list[3] = {1, 2};
    //same time complexity and space complexity for both Adj mat, adj list
    //BUT adj mat will take O(n^2) everytime because we have to set the matrix
    //values to 0. But for adj list, it's O(E) when the number of nodes is
    //comparatively less(sparse matrix. less edge number). But worst case will
    //take this to O(n^2)

    //for sparse graph, the adjacency list will give O(E) TC, SC

//    3
// 0 ---> 1
//  \    ^        for directed weighted graph
// 2 \  / 4
//    v/
//    02
    adjwlist[0].push_back({1,3});
    adjwlist[2].push_back({1,4});
    adjwlist[0].push_back({2,2});

    for(int i=0; i<nodes; i++)
    {
        //O(n^2)
        cout<<i<<" -> ";
        for(auto j : adj_list[i])
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }

    cout<<"\nFor the directed weighted graph: \n";
    for(int i=0; i<3; i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<adjwlist[i].size(); j++)
        {
            cout<<"("<<adjwlist[i][j].first<<","<<adjwlist[i][j].second<<")"<<" ";
        }
        cout<<"\n";
    }

//    cout << "\nFor the directed weighted graph: \n";
//    for (int i = 0; i < nodes; i++)
//    {
//        cout << i << " -> ";
//        for (auto edge : adjwlist[i])
//        {
//            cout << edge.first << "(" << edge.second << ") ";
//        }
//        cout << "\n";
//    }

    return 0;
}
