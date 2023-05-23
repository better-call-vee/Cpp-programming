#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;
};

bool compare(Item i1, Item i2) // this function find the value of the single factor and compare which
// item has more object value.
{
    double ratio1 = (double)i1.value / i1.weight;
    double ratio2 = (double)i2.value / i2.weight;
    return ratio1 > ratio2; // return true if i1 is greater than i2. and the sort function do
    // comparison according to that
}

double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (const Item &item : items) // taking every element of the items vector from the beginning
    // in this way, we will take the most valued object first because we have sorted the vector in such
    // a way
    {
        if (capacity >= item.weight) // checking if we take the full proportional of the object will
        // it exceed the capacity or not.
        {
            totalValue += item.value; // adding the taken object's value to the totalValue variable
            capacity -= item.weight;  // substracting the taken object's weight from the capacity
        }
        else
        {
            totalValue += (double)item.value / item.weight * capacity; // now if the current object's
            // weight is exceeding the capacity we would simply add the fractional value to the
            // totalValue which is the product of the remaining capacity and the single factor value of
            // that item
            break;
        }
    }

    return totalValue;
}

int main()
{
    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);
    for (int i = 0; i < numItems; i++)
    {
        cout << "Enter the weight and value of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value obtainable: " << maxValue << endl;

    return 0;
}
