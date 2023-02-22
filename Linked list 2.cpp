//It's a linear and dynamic data structure whereas an array is a linear static data
//structure.
//linear means it stays in a line. we can traverse from starting and ultimately
//will traverse everything.
//non linear structure can be a tree.
//            T
//          T   T
//         T T  T T
//Linked list isn't sequential memory picker like array
//10 15 20 22     arbitrarily
// _  _  _  _

//array won't allow you an array of size 10^9. but linked list will
//Stack, queue, dequeue type data structures need linked list


///STRUCTURE
//Now, if we wanna create a linked list memory, suppose, we want to store
//1,2,3,4
// head(10)     14      20        28
// [1][14]  [2][20]  [3][28]  [4][NULL]    these are called 'node' [1],[2]...
//here, every element has a pointing memory


///INSERTION AT HEAD
//  35         10
//[5][10]   [1][14]
//so now:
// head(35)     10         14      20        28
// [5][10]    [1][14]  [2][20]  [3][28]  [4][NULL]    O(1)
//but array will take O(n) complexity


///SEARCHING FOR VALUES
//array could complete this with O(1) complexity becuase, it follows this
//startaddress+index*(memory size).
//but for linked list, it doesn't know initially where the specific value is!
//suppose our wanted element is in index 3, so only index 2 knows it's address.
//then we can't complete this process with O(1) complexity. O(n)
//we can't do binary search with linked list because it will take O(nlogn) com
//we will do only linear search


//Linked lists and arrays are both data structures that can be used to store a
//collection of elements, but they have some key differences in terms of memory
//usage.
//
//One of the main advantages of an array is that it has a fixed size, so once it
//is created, it will use a fixed amount of memory. Because of this, arrays are
//considered to be a more memory-efficient data structure than linked lists,
//especially when the size of the array is known in advance.
//
//On the other hand, a linked list consists of a series of nodes, each of which
//contains a value and a reference to the next node in the list. Because each node
//in a linked list has a reference to another node, a linked list uses more memory
//than an array to store the same number of elements.
//
//However, linked lists have the advantage of being more dynamic than arrays, as
//they can grow or shrink in size as elements are added or removed. With an array,
//you may have to create a new one and copy all elements when you need more space,
//and in the case when elements are removed, it will leave empty spots.
//
//Additionally, linked lists can allow for constant time insertion and deletion
//at the front of the list. While arrays will take O(n) time to shift elements
//over to make space.
//
//In summary, arrays use less memory than linked lists, but linked lists are more
//dynamic and efficient when it comes to inserting or deleting elements. The
//choice between them usually depends on the specific requirements of the problem
//you're trying to solve.
