//Problem Statement
//
//You have given a number. Your task is to find if the number is divisible by 11
//or not.
//
//There is a way you can find a number is divisible by 11 or not very easily:
//
//Suppose the number is 62524.
//
//For 62524 , if we go from right to left and we take Odd position digit sum =
//4+5+6 = 15
//
//For 62524 , if we go from right to left and we take Even position digit sum =
//2+2 = 4
//
//Now we find the absolute difference = Odd position digit sum - Even Position
//digit sum = 15 - 4 = 11
//
//If the absolute difference is divisible by 11 then, we can say that the number
//is divisibe by 11.
//
//If the absolute difference is not divisible by 11 then, we can say that the
//number is not divisibe by 11.
//
//Input Format
//
//You will be given a number as input.
//Constraints
//
//1 <= number <= 10^100
//Output Format
//
//If number is divisible by 11 then print YES otherwise print NO

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    int oddsum = 0;
    int evensum = 0;
    for (int i = 0; i < n.size(); i++) {
        if ((i + 1) % 2 != 0) oddsum += (n[i] - '0');
        else evensum += (n[i] - '0');
    }

    if (abs(oddsum - evensum) % 11 == 0) cout << "YES";
    else cout << "NO";

    return 0;
}


//We use a string to read in the number, instead of a long int. This is because
//the number could be up to 10^100, which is larger than the maximum value for a
//long int.
//
//We initialize oddsum and evensum to 0 as integers, not long integers.
//
//We use a simpler loop that goes from left to right, and we use the ASCII value of
//'0' to convert the character representation of each digit to an integer.
//
//We use abs(oddsum - evensum) to calculate the absolute difference between the odd
//and even digit sums.
