// Multiset and set have the same property but Multiset allows duplicate
// elements.

#include <bits/stdc++.h>
using namespace std;
int main() {
    multiset<int> a;

    // O(logn)
    a.insert(5);
    a.insert(7);
    a.insert(4);
    a.insert(3);
    a.insert(4);
    a.insert(7);

    cout << "Printing the multiset: ";
    for(auto it : a) cout << it << " ";
    cout << "\n";

    cout << "Size of the multiset: " << a.size() << "\n";

    // O(logn) -> erase all occurance
    a.erase(4);
    cout << "Printing the multiset after commanding a.erase(4): ";
    for(auto it : a) cout << it << " ";
    cout << "\n";

    // suppose, we want to just erase one of them.
    /// erase a single occurance
    a.erase(a.find(7));
    // here a.find() is giving the memory address to erase and it's deleting
    // that. when executing this, we have to make sure that actually that value
    // exists in the multiset. otherwise, it will return end(), which will be
    // responsible to crash the whole multiset

    cout << "Printing the multiset after commanding 'erase single occurance': ";
    for(auto it : a) cout << it << " ";
    cout << "\n";

    /// THE find() function's mechanism is as same as set.

    // there is a more efficient method for erasing and reinserting.
    // that's extract();
    multiset<int> s = {1, 2, 3, 4, 5};
    int largest = *s.rbegin(); // Identify the largest element

    auto node = s.extract(largest); // only one occurance erased
    // Extract the node containing the largest element
    // At this point, `s` no longer contains `largest`, and `node` holds the
    // extracted element.
    // The extracted node can be directly reinserted into s or another
    // multiset<int>:
    multiset<int> another_set;
    another_set.insert(move(node));
    // Move the extracted node to another set
    // Now, `another_set` contains the element `largest`, and `s` has been
    // modified accordingly.
    /*
    Efficiency: Using extract() is particularly efficient when you need to
    remove and then process or reinsert an element. It saves on the cost
    associated with re-allocation and re-insertion since the node's allocation
    is preserved.

    Direct Manipulation: While extract() itself does not allow for direct
    manipulation of the element's value (in the case of std::set or
    std::multiset, where the value is the key), it facilitates easy transfer and
    handling of elements between containers.

    Versatility: extract() can be used in a variety of scenarios, such as
    adjusting the organization of elements based on runtime conditions,
    efficiently modifying container contents, or implementing complex data
    structures that require frequent and conditional reorganization of elements.

Why Move?
Efficiency: Moving a node handle transfers ownership of the underlying resources
(such as dynamic memory) without duplicating them. It avoids the overhead
associated with copying the element, such as dynamic memory allocation and
deallocation, which can be costly in terms of performance, especially for
complex objects or when such operations occur frequently.

Safety: Since the node handle is not copyable (copy operations are deleted for
node handle types), moving ensures that the original node handle is left in a
valid but unspecified state, preventing accidental use after it has been
transferred.

Semantic Clarity: Using std::move explicitly indicates that ownership of the
resources is being transferred, making the code's intent clearer to readers and
maintainers.
    */

    return 0;
}
