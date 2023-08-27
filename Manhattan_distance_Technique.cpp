#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    /*
    Point(int x, int y) {
    this->x = x;
    this->y = y;
    }
    */
};

int computeSharedPath(const Point &a, const Point &b, const Point &c)
{
    int sharedX = 0, sharedY = 0;

    // Check for shared path in x-direction without causing overflow
    if ((b.x - a.x > 0 && c.x - a.x > 0) || (b.x - a.x < 0 && c.x - a.x < 0))
        // Both are moving in the same direction
        sharedX = min(abs(b.x - a.x), abs(c.x - a.x));

    // Check for shared path in y-direction without causing overflow
    if ((b.y - a.y > 0 && c.y - a.y > 0) || (b.y - a.y < 0 && c.y - a.y < 0))
        // Both are moving in the same direction
        sharedY = min(abs(b.y - a.y), abs(c.y - a.y));

    return sharedX + sharedY + 1; // +1 for the starting cell
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        Point a(0, 0), b(0, 0), c(0, 0);
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        cout << computeSharedPath(a, b, c) << "\n";
    }

    return 0;
}


/*

Imagine Bob, Carol, and Alice are in a city with a grid-like structure (think Manhattan). They all start from Alice's house. Bob wants to get to his house and Carol to hers. Both Bob and Carol want to walk together as much as possible, but they also want to take the shortest route to their own homes. The question is: How long can they walk together before they have to part ways?

Concept:
Manhattan Distance: This city grid resembles a chessboard. Unlike a bird that can fly directly (in a straight line) to a destination, people here walk like kings on a chessboard. They can move horizontally or vertically, but not diagonally. The total number of blocks they walk, combining horizontal and vertical, gives the Manhattan distance between two points.

Direction Matters: It's not just how far Bob and Carol's houses are, but also in which direction. If both houses are to the North, they'll walk together to the North. If one house is to the North and the other to the South, they'll part ways immediately.

Solution:
Compute Individual Distances: First, calculate how far Bob and Carol have to walk horizontally (East-West) and vertically (North-South) to get to their respective homes from Alice's.

Shared Path: Determine the shared path by looking at their walking directions:

If both have to walk East, they'll walk together until one of them reaches their house.
If one has to walk East and the other West, they won't walk together at all in the horizontal direction.
Repeat the same logic for the vertical (North-South) direction.
Summation: Add the shared horizontal and vertical paths to get the total number of blocks they walk together. Add 1 for Alice's block, where they start.

Analogy:
Imagine you and a friend are at a starting point in a maze. Both of you have different exits but want to stay together as long as possible. You have a map, so you know the shortest paths to your respective exits. You'll walk together in the maze until a junction forces you to part ways. Your journey together is the shared path.

With this summary, even years from now, you should be able to recall the essence of the problem and the approach to solve it.
*/