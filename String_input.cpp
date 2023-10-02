//Full Line Input:
//Reads the entire line, including spaces.
string line;
getline(cin, line);

Important: If using after cin >>, clear the buffer:
cin.ignore();

//let's explore
int num;
string line;
cin >> num;       // Let's say user inputs: 42[Enter]
getline(cin, line);  // This will read just the newline left over by cin >>, not the next actual line of input.
cout << line;     // This will output an empty line.

By using cin.ignore() between cin >> num and getline(cin, line), I
can ensure that getline reads the next full line of input as intended.

