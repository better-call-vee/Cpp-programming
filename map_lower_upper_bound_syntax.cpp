#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> exampleMap = {{1, "Apple"}, {3, "Banana"}, {5, "Cherry"}};

    auto lower = exampleMap.lower_bound(3);
    auto upper = exampleMap.upper_bound(3);

    if(lower != exampleMap.end()) {
        cout << "Lower bound for key 3 is (" << lower->first << ", "
             << lower->second << ")\n";
    } else {
        cout << "Lower bound for key 3 not found\n";
    }

    if(upper != exampleMap.end()) {
        cout << "Upper bound for key 3 is (" << upper->first << ", "
             << upper->second << ")\n";
    } else {
        cout << "Upper bound for key 3 not found\n";
    }

    return 0;
}
