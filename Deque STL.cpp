#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // Initialize a deque with fixed elements {1, 2, 3}
    deque<int> dq = {1, 2, 3};

    // push_back: Insert an element at the end of the deque
    dq.push_back(4);
    // Deque becomes: 1 2 3 4
    // Complexity: O(1)

    // push_front: Insert an element at the beginning of the deque
    dq.push_front(0);
    // Deque becomes: 0 1 2 3 4
    // Complexity: O(1)

    // pop_back: Remove the last element of the deque
    dq.pop_back();
    // Deque becomes: 0 1 2 3
    // Complexity: O(1)

    // pop_front: Remove the first element of the deque
    dq.pop_front();
    // Deque becomes: 1 2 3
    // Complexity: O(1)

    // front: Get the first element of the deque
    cout << "Front element: " << dq.front() << endl; // Outputs 1
    // Complexity: O(1)

    // back: Get the last element of the deque
    cout << "Back element: " << dq.back() << endl; // Outputs 3
    // Complexity: O(1)

    // size: Get the number of elements in the deque
    cout << "Size of deque: " << dq.size() << endl; // Outputs 3
    // Complexity: O(1)

    // empty: Check if the deque is empty
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << endl; // Outputs No
    // Complexity: O(1)

    // clear: Remove all elements from the deque
    dq.clear();
    // Deque becomes empty {}
    // Complexity: O(n)

    // Re-initialize the deque for the next operation
    dq = {1, 2, 3};

    // []: Access the element at a specific index
    cout << "Element at index 2: " << dq[2] << endl; // Outputs 3
    // Complexity: O(1)

    // Print the current state of deque
    cout << "Current deque: ";
    for (int num : dq)
    {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
