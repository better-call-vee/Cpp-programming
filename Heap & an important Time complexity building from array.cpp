#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int>nodes;

    Heap()
    {

    }

    void down_heapify(int idx)
    {
        while(1)
        {
            int largest = idx;
            int l = 2*idx + 1;
            int r = 2*idx + 2;
            if(l<nodes.size() && nodes[largest] < nodes[l]) largest = l;
            if(r<nodes.size() && nodes[largest] < nodes[r]) largest = r;
            if(largest==idx) break;
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }

//         1
//       /   \
//      2     3
//     / \   / \
//    4  10 9   8
//   /
//  7
//here the last leaf node is 7. A non-leaf node is any node in the tree that has
//at least one child which will be the parent of the leaf node(n/2-1).
    void build_from_array(vector<int>a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = n/2 - 1;
        for(int i=last_non_leaf; i>=0; i--)
        {
            down_heapify(i); //now everytime this down_heapify with different
            //i value will fix the heap and the final output will be
//            10
//         /      \
//        7        9
//      /  \     /   \
//     4    2   8     3
//    /
//   1
        }
    }
//downheap's complexity is logn, we can think that build heap's complexity will
//be nlogn. but no, it's O(n)
//suppose, we are giving input a complete binary tree.
//                           ●                             height=>3
//             ┌─────────────┴──────────────┐
//             ●                            ●              height=>2
//      ┌──────┴──────┐              ┌──────┴──────┐
//      ●             ●              ●             ●       height=>1
//   ┌──┴──┐       ┌──┴──┐        ┌──┴──┐       ┌──┴──┐
//   ●     ●       ●     ●        ●     ●       ●     ●    height=>0
//each height's node count => |n/(2^(h+1))|. here | is being considered as the
//ceil symbol. for h=0, 15/2, ceil will be 8 and this level has 8 nodes.
//for h=1, 4 and so on.
//logn
//   ∑  h*|n/(2^(h+1))| , we are taking the summation for all nodes present
//   0
//a complete binary tree will have height from 0 to logn.
//To make calculation easier and analysis of time complexity, we are making it
//logn
//   ∑  h*|n/(2^h)|
//   0
//n is constant, so:
//    logn
//  n*   ∑  h/(2^h)
//     n=0
//we can take this ∑ series to infinite(∞) instead of logn because obviously
//∞ is bigger than logn. we can replace any thing with greater than that thing
//easily in time complexity.NOW:
//∞
//∑  h/(2^h)
//0
//there's an equation:
//∞
//∑  x^n = 1/(1-x) when x>0, x<1.
//0
//=> n*(x^(n-1)) = 1/(1-x)^2 (after differentiating both sides)
//=> n*x^n = x/(1-x)^2. (multiplying x both sides)
//now we can compare the left side with the 84th line equation. n=h, x = 1/2
//after calculation:
//∞
//∑  h/(2^h)  =  2
//0
//so, if the infinite can make it to 2, logn will be less than that.
//so, for the 78th line, after calculation, it will be 2n. which will be
//eventually n.
///SO, THE TIME COMPLEXITY IS O(n).

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
    vector<int>inp = {1,2,3,4,10,9,8,7};
    heap.build_from_array(inp);
    heap.PrintHeap();
    return 0;
}
