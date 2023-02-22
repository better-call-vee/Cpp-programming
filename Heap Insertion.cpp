///MAX HEAP INSERTION.
//We will represent it with array.
//0th index will be the root.

//                     __0(80)__
//                    /         \
//              __1(65)__       2(72)
//             /         \     /    \
//          3(50)       4(35) 5(60) 6(40)
//         /    \      /    \
//      7(20)  8(30) 9(25)  10(10)

//here, 80's index no. is 0. 80's left is 65 and it's index no. is 1, 72's is 2.
///current index's left index => 2i+1;
///current index's right index => 2i+2;
///parent index => (i-1)/2;
//up_heapify
#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int>nodes;

    Heap()
    {

    }

    //suppose, a tree.
//          10
//        /    \
//       5      7
//     /  \    /  \
//    3    2  6    4
//we want to insert 8 here. so, 8 will be pushed back to it. currently, the
//vector is [10,5,7,3,2,6,4]. after pushing back [10,5,7,3,2,6,4,8]
//now we will call up_heapify function with input of 7(size-1).
//in the function, it will run until idx is reaching root and current node is
//bigger than parent node. (idx-1)/2 is the parent index. Currently, 8 is
//3's child. it meets the while condition. now it will be swapped with the parent
//index and idx will be equal to the parent idx.now idx is 3 and it's value is 8.
//it's parent is 5 and it's less than 8. so again swapping. now the while loop
//will be broken.

//complete binary tree's height is logn. So, for the worst case, the complexity
//will be O(logn).
    void up_heapify(int idx)
    {
        while(idx > 0 && nodes[idx] > nodes[(idx-1)/2])
        {
            swap(nodes[idx], nodes[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }

    void insert(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size()-1);
    }

    //O(n)
    void PrintHeap()
    {
        for(int i=0; i<nodes.size(); i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }
};

int main ()
{
    MaxHeap heap;
    heap.insert(4);
    heap.insert(7);
    heap.insert(9);
    heap.insert(1);
    heap.insert(10);
    heap.PrintHeap();
    return 0;

//           10
//         /    \
//        9      7
//       / \
//      1   4
}
