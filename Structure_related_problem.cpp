#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person {
    string name;
    int birthYear;
};

bool comparePersons(const Person& a, const Person& b) {
    // Sort in descending order of birth years (younger to older)
    return a.birthYear > b.birthYear;
}

int main() {
    int T, n;
    cin >> T; // Read the number of test cases

    for (int i = 0; i < T; ++i) {
        cin >> n; // Read the number of people
        vector<Person> people(n);

        for (int j = 0; j < n; ++j) {
            cin >> people[j].name >> people[j].birthYear;
        }

        // Sort the vector using the custom comparator
        sort(people.begin(), people.end(), comparePersons);

        // Print the sorted names
        for (const Person& person : people) {
            cout << person.name << '\n';
        }

        // Print a blank line after each test case if it's not the last case
        if (i < T - 1) {
            cout << '\n';
        }
    }

    return 0;
}
