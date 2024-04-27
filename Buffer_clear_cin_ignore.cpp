/*
cin.ignore(numeric_limits<streamsize>::max(), '\n');

1) Transition from cin to getline(): When switching from using cin to getline(),
it's common to have a leftover newline character in the input buffer. This
occurs because cin typically reads input up to a delimiter (like a space) and
stops, leaving the delimiter in the buffer. If you read an integer or a
floating-point number before this, pressing 'Enter' adds a newline character to
the buffer, which getline() will consider as the end of input if not cleared.
*** delimeter is a character which defines as a boundary.

2) Ignore as many characters as possible: The reason to ignore as many
characters as possible is to ensure that the entire buffer is cleared,
regardless of its current size. This is a defensive programming practice to
handle cases where the buffer might contain more characters than expected, which
can happen if the user inputs extra characters accidentally or if there's an
unexpected input format.

3) Why the newline character ('\n')?: The newline character is specified as the
delimiter because it's the typical end-of-line marker in input streams. By
ignoring all characters up to and including the newline, you ensure that you're
starting fresh for the next read operation.

4) Why use numeric_limits<streamsize>::max()?: This value is used to specify the
maximum number of characters to ignore. Since you often don't know how many
characters need to be ignored (it could be none, it could be many if the user
entered additional characters), you specify the maximum possible value to ensure
the buffer is completely cleared up to the next newline.
*/

// code for example: https://codeforces.com/contest/52/submission/254878557