/*
3 5 8 7 2 1
here, if they want a subarray sum from l = 2 to r = 4, we can easily give
the output by prefix_sum[4] - prefix_sum[1];

but what if they want to know the sum of a range EVERYTIME, in every query,
while upgrading only 1 index at a time??

suppose, an array :
 3 5 7 8 7 3 1 9
 they want to know the sum from l=3 to r=6?
 We will divide the array like binary index tree(at most two nodes per node)

                                 ___________[1-8: Sum]_____________
                                /                                  \
                _______[1-4: Sum]_______                    _______[5-8: Sum]_______
               /                        \                  /                        \
        [1-2: Sum]                   [3-4: Sum]          [5-6: Sum]                [7-8: Sum]
        /         \                   /       \          /       \                /          \
    [1: 3]       [2: 5]           [3: 7]    [4: 8]    [5: 7]    [6: 3]         [7: 1]      [8: 9]

every node will be containing the sum of it's children. We will save it down
at first.

Now,
Everytime while dividing, there will be logn levels in total. n elements:
n = 2^level
and level = log2(n)
It's quite like Merge Sort.
For 10^5, there will be 17 levels
if, n is 2's power(n = 2^k)
then, there will be 2*n - 1 nodes.

per level:
2^0 + 2^1 + 2^2 + ... 2^k = 2^(k + 1) - 1; (formula) => S = a(1 - r^n) / (1 - r), where a is 2^0, n is k + 1, r is 2.
=> n . 2^1 - 1 (in total)

***SO, if n = 2^k(2's power), there will be 2n - 1 nodes

what if n is not 2's power??
Then there will be at most 4n - 1 nodes.
we will simply extend the 2's power to the next.
suppose, n = 7, so 2's power is 2 now. we will go to 2^3.
so 2^(k + 1):
now the 34th line's sum will be 2^(k + 2) - 1.
and thus, n * 2^2 - 1.

and => 4n  - 1(AT MOST AND IN WORST CASE)

                 ith (parent node)
               /     \
           2i-th     2i+1 -th  (left and right child node)

We will imagine it like a tree and we will work using vector/array



NOW,
                                 ___________[1-8: Sum]_____________
                                /                                  \
                _______[1-4: Sum]_______                    _______[5-8: Sum]_______
               /                        \                  /                        \
        [1-2: Sum]                   [3-4: Sum]          [5-6: Sum]                [7-8: Sum]
        /         \                   /       \          /       \                /          \
    [1: 3]       [2: 5]           [3: 7]    [4: 8]    [5: 7]    [6: 3]         [7: 1]      [8: 9]

    Again look at this, suppose, they want to know 1 to 6's sum, we will need the 2nd node and
    the 6th node(5-6 sum);

    But, How will We know that which nodes to take????
	=> Suppose, they want to know sum of 4 to 6th sum. now what?
	We start from the root node and start a recursive approach and it goes down.
	We call each child node as the parent node.
	So, [1-8] goes calling [1-4], [5-8].
	is [1-4] in range(i = 1, j = 4. we check l >= i && r <= j)? No, so, we go down.
	[1-2] in range? no. we go down. and both 1 and 2 are not in range. As we 
	have reached the leaf nodes, we now turn back. Now, back to [3 - 4], is it
	in range?? no. then we go down. 3? no. 4? yes. and we get one of our range. 
	and return the sum and get back to [5-8].

	***WE ONLY ADD THE SUM WHEN l >= i and r <= j. Think about it. WHEN THE RANGE is 
	in between our desired range, we go on.

	***Here is a thing, we won't totally visit the range node which is totally out of
	our desired range, suppose, [1 - 3] was a node here, we won't totally visit this node
	because it's out of the league! same goes if [7 - 8] here. 
	SO,if i > r or j < l , we give up for that side of node.

	now: 
	[5-8], in range? no.
	go to [5-6], in range? yeah baby. okay, so we are done. we are back to root.
	And thus, the sum of returned sums is our answer.



COMPLEXITY:
-----------
There will be at most 4n nodes traversal.

It may seem like we are traversing almost all the nodes by observing a 
small tree.

Hypothesis: how many nodes it will traverse on a level?
=> At most 4 nodes at worst case!!
How tf?
=>
suppose, we have reached at a place of the tree where 4 nodes have been visited.
    <-----------------------------> suppose this is the range of sum we require
 _______   _______   _______   _______
 |     |   |     |   |     |   |     |

 see, the two ranged we need have covered two of the four nodes. thus, those
 two nodes won't be visited further, and we will visit two nodes only(1st and 4th).

 So, at worst case, only 4 nodes will be visited per level.

TIME COMPLEXITY => 4 * logn;

*/
