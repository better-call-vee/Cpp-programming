//It's a recursive function. Base case of merge sorting -> [ ] = [ ]
//[a] = [a]
//given 2 sorted arrays, now we need to merge.
//suppose, a = {5, 3}; b = {2, 7, 1}; c = {5, 3, 2, 7, 1}
//suppose, given an array c. declaring a function merge.sort(c).
//If it's size is not 1 or 0. then must be >=2. then it will say, no I can't sort.
//or, if it's 1 or 0, then it will return 1st or 2nd line.
//But c's size is not that. It will devide the array into a and b.
//now the merge.sort(c) expecting two sorted arrays. then it will merge them
//getting in return {3, 5} , {1, 2, 7} . we donno how. now, it will merge
//{1, 2, 3, 5, 7}.
//dividing the work until it reaches base case.
//              [5, 3, 2, 7, 1]
//       [5, 3]                 [2, 7, 1]
//     [5]    [3]              [2]     [7, 1]
//now, 5,3,2 will be returned
//                                [7] [1]
//7,1 will be returned. they will be sorted, donno how. but will be sorted to [1,7]
//so, from [2, 7, 1], we are getting merged [1, 2, 7]
//and from [5,3] we are getting [3,5]
//now the last merged answer is [1,2,3,5,7]
// a=[5, 3], b=[2, 7, 1].  c for comparing
//a[0] (c) b[0]. b[0] stays. suppose, sorted array = d. d=[2] now
//ok, a[0] again with b[1] because b[0] has been taken. so, a[0] < b[1], a[0] stays
//continuing this, the last answer will be [1,2,3,5,7], O(a.size()+b.size()) = O(n)

//each step n gets divided . n -> n/2 -> n/3 -> n/n. harmonic series detected
//Time complexity -> levels*every level's merging complexity = logof2based_n * n
//O(nlogn)
#include<bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int>a)
{
    if(a.size()<=1) return a; //base case

    int mid = a.size()/2;

    vector<int>b;
    vector<int>c;

    for(int i=0; i<mid; i++)
    {
        b.push_back(a[i]);
    }
    for(int i=mid; i<a.size(); i++)
    {
        c.push_back(a[i]);
    }

    vector<int>sorted_b = merge_sort(b);
    vector<int>sorted_c = merge_sort(c);

    vector<int>sorted_a;
    int idx1 = 0;
    int idx2 = 0;

    for(int i=0; i<a.size(); i++)
    {
        //if index of any sorted divided array gets to end index then:
        if(idx1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if(idx2 == sorted_c.size()) {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }

        if(sorted_b[idx1] < sorted_c[idx2])
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
    }
    return sorted_a;
}

int main ()
{
    vector<int>a = {5,3,7,1,8,9};
    vector<int>ans = merge_sort(a);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}

//When the merge_sort() function is called on the input array [5, 3, 7, 1, 8, 9],
//it first divides the array into two smaller arrays: [5, 3, 7] and [1, 8, 9].
//These smaller arrays are then recursively sorted using the merge_sort() function
//itself.
//For the first call to merge_sort(), the input array is [5, 3, 7]. This array is
//divided into [5] and [3, 7], and the merge_sort() function is called on both of
//these arrays.
//For the second call to merge_sort(), the input array is [3, 7]. This array is
//divided into [3] and [7], and the merge_sort() function is called on both of
//these arrays.
//At this point, all of the recursive calls to merge_sort() have reached arrays
//of size 1, and the function returns the sorted arrays [3] and [7]. These arrays
//are then merged to form the sorted array [3, 7].
//The sorted arrays [5] and [3, 7] are then merged to form the sorted array
//[3, 5, 7].
//The process is repeated for the second half of the input array, and the sorted
//arrays [1] and [8, 9] are merged to form the sorted array [1, 8, 9].
//Finally, the sorted arrays [3, 5, 7] and [1, 8, 9] are merged to form the
//sorted array [1, 3, 5, 7, 8, 9], which is the output of the program.
