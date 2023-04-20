#include <stdio.h>

int main()
{
    char check;
    scanf("%c", &check);
    if(check == ' ') {
        printf("It is a whitespace character\n");
    }
    else printf("It is not a whitespace character\n");

    return 0;
}




/*
GCD is the greatest common divisor of the given numbers. So, to
find GCD we have to loop through the numbers and check if a number
divides them both or not. And then we have to find the greatest among
the divisors if multiple divisors are there.
Here in the program, we take two numbers at first and then we
set the value of GCD to 1 because if no number is found, 1 will be the
usual GCD of them.
Then we run a for loop from 1 to the greater number of the two numbers
given by using the condition (i<=one && i<=two). Everytime we check if
the i divides both one and two! If yes, then we change the GCD because
everytime the i is increasing.
Finally, we print the GCD.
*/
