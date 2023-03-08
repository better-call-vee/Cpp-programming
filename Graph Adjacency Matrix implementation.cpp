#include<bits/stdc++.h>
using namespace std;

//(0)A----B(1)
//        /\         Total nodes = 4          0->1; 1->0; 1->2; 2->1; 1->3; 3->1;
//       /  \        Total edges = 4          2->3; 3->2;
//      /    \       Undirected + Unweighted
//     /      \
// (2)C--------D(3)

int main ()      //space complexity is O(n^2)
{

    int nodes = 4; //O(1)
    int matrix[nodes][nodes] = {}; //will set the values of the matrix to 0. O(n^2)

    matrix[0][1] = 1;    //it's TC will be O(E). E=number of edges
    matrix[1][0] = 1;    //for worst case scenerio, A---B; here both sides can
    matrix[1][2] = 1;    //contain n number of edges. then the TC will be O(n^2)
    matrix[2][1] = 1;
    matrix[1][3] = 1;
    matrix[3][1] = 1;
    matrix[2][3] = 1;
    matrix[3][2] = 1;

    for(int i=0; i<nodes; i++) //O(n^2)
    {
        for(int j=0; j<nodes; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
