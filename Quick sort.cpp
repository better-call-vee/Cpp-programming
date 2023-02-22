//sort this array [1,5,3,7,2,9,8]
//we pick a random number, I'm picking 7. to the left of 7 there'll be the values
//less than 7 or 7 and to the right of 7 there'll be the values greater than 7.
//1,5,3,2 -> 7 <- 9,8
//sort those two sides.
//1,2,3,5 -> 7 <- 8,9
//so, now the both sides will do the same thing
//1,2 -> 3 <- 5.     empty -> 8 <- 9
//empty -> 1 <- 2.
//returning from left side -> 1,2,3,5.
//returning from right side -> 8,9.
//here, "pivot" element = 7.
//divide and conquer algortithm (merge and quick sorting)
//divide -> 1. pivot choose, 2. all elements <=pivot> all elements
//conquer -> left side will be pushed first to the main merged sorted array because
//they are the smallest elements compared to pivot. then pivot. then the right
//side elements.
//pivot can be any element. but the problem is, if the pivot is at the last index
//then the left array will be large. n-1 sized. and there will be less levels

#include<bits/stdc++.h>
using namespace std;

vector<int>quick_sort(vector<int>a)
{
    if(a.size()<=1) return a;
    int pivot = rand()%(a.size());

    vector<int>b,c;
    for(int i=0; i<a.size(); i++)
    {
        if(i==pivot) continue;
        if(a[i] <= a[pivot]) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    vector<int>sorted_b = quick_sort(b);
    vector<int>sorted_c = quick_sort(c);
    vector<int>sorted_a;

    for(int i=0; i<sorted_b.size(); i++)
    {
        sorted_a.push_back(sorted_b[i]);
    }

    sorted_a.push_back(a[pivot]);

    for(int i=0; i<sorted_c.size(); i++)
    {
        sorted_a.push_back(sorted_c[i]);
    }

    return sorted_a;
}

int main ()
{
    vector<int>a = {1,5,3,7,2,9,8};
    vector<int>sorted_a = quick_sort(a);
    for(int i=0; i<sorted_a.size(); i++)
    {
        cout<<sorted_a[i]<<" ";
    }
    return 0;
}

///QUICK SORT TIME COMPLEXITY
//ususally on average O(nlogn)
//if the pivot is the last element, then the time complexity will be O(n^2)
//because, there will be n level and each level's complexity is O(n).

//if the pivot element is the mid element,
//each step's level is getting divided by 2, so level = log(n). each level's
//complexity = O(n) . so, O(nlogn)

//so, time complexity depends on pivot choosing
//to solve this, we will choose pivot randomly. (0, sz-1)
//or, we will shuffle the array randomly. then one side will get 25%, other
//will get 75%.maximum level will be got in the 75% side.
//(n/4)  (3n/4). k=level. ((3/4)^k)*n=1 -> n = (4/3)^k. -> log(4/3based)n
//n=a^b -> b=log(a based)n theory
//so, if we choose random shuffle pivot, the complexity will be O(log(4/3based)n)

//or, we will fix the pivot from the beginning
