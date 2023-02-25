//You are given a ladder array of n integers. You need to sort it using a Deque.
//You can use built-in Deque for this problem. The Expected Time Complexity is O(n).
//A ladder array is an array that is increasing at first and then decreases after
//that.
//For example: [1,3,5,7,2,0] is a ladder array because 1 < 3 < 5 < 7 > 2 > 0.
//It is increasing till value 7, then it is decreasing after that.
//
//Input
//6
//1 3 5 7 2 0
//Output
//0 1 2 3 5 7
//
//Input
//5
//4 6 2 1 0
//Output
//0 1 2 4 6


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, inp;
    cin >> n;
    deque<int> ladarr;
    for(int i = 0; i < n; i++)
    {
        cin >> inp;
        ladarr.push_back(inp);
    }
    vector<int>out;
    while(ladarr.size() > 1) //do simulation with the given inputs. you'll
        //easily understand why you've taken this condition.when there will be
        //a single element left in the deque, you can't compare. then break the
        //loop and push that single mofo into the vector.
    {
        // Remove front and back elements and compare
        int cmp1 = ladarr.front(); // Get the first element of the deque
        int cmp2 = ladarr.back();  // Get the last element of the deque
        ladarr.pop_front();        // Remove the first element
        ladarr.pop_back();         // Remove the last element
        // Insert elements in correct order
        if(cmp1 < cmp2)  // If the first element is smaller than the last
        {
            out.push_back(cmp1);// Add the first element to the back of the output vector
            ladarr.push_front(cmp2); // Add the last element to the front of the original deque
        }
        else            // If the last element is smaller than the first
        {
            out.push_back(cmp2);   // Add the last element to the back of the output
            ladarr.push_front(cmp1); //Add the first element to the front of the original deque
        }
    }

    if(!ladarr.empty())
    {
        out.push_back(ladarr.front());
    }

    for(auto val:out)
    {
        cout<<val<<" ";
    }

    return 0;
}

