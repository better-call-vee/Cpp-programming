#include<bits/stdc++.h>
using namespace std;

void fun(int l,int r)
{
    int mid = (l+r)/2;
    for(int i = l ; i <= r ; i++)
    {
        cout<<i<<endl;
    }
    if(l<r)
    {
        fun(l,mid);
        fun(mid+1,r);
    }
}

int main()
{
    int n;
    cin>>n;
    fun(0,n-1);
    return 0;
}

//In the fun function, the range of input parameters (l, r) is divided into two
//equal parts, which are (l, mid) and (mid+1, r), where mid is the middle index
//of the range (l, r) and is computed as mid = (l+r)/2.
//
//This division of the range into two parts can be visualized as a binary tree,
//where each node in the tree represents a call to the fun function with a range
//of input parameters (l, r). The root node of the tree represents the initial
//call to fun(0, n-1), and the leaf nodes represent calls to fun(l, r) where l=r.
//
//At each level of the recursion, the range of input parameters is divided into
//two parts, resulting in two child nodes for each parent node in the binary tree.
//The process of dividing the range into two parts and creating child nodes
//continues until the base case is reached, which is when l >= r.
//
//Since the range is divided into two equal parts at each level of the recursion,
//the height of the binary tree is log n, where n is the size of the input range
//(0, n-1). This means that the number of levels in the binary tree is log n,
//which is the same as the number of times the function fun is called recursively.
//
//Thus, the time complexity of the function fun can be analyzed in terms of the
//number of levels in the binary tree and the time complexity of each level,
//resulting in a time complexity of O(n log n).
