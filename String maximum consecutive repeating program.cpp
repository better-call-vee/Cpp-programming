// C++ program to find the maximum consecutive
// repeating character in given string
#include<bits/stdc++.h>
using namespace std;

// function to find out the maximum repeating
// character in given string
char maxRepeating(string str)
{
	int len = str.length();
	int count = 0;

	// Find the maximum repeating character
	// starting from str[i]
	char res = str[0];
	for (int i=0; i<len; i++)
	{
		int cur_count = 1;
		for (int j=i+1; j<len; j++)
		{
			if (str[i] != str[j])
				break;
			cur_count++;
		}

		// Update result if required
		if (cur_count > count)
		{
			count = cur_count;
			res = str[i];
		}
	}
	return res;
}

// Driver code
int main()
{

	string str = "aaaabbaaccde";
	cout << maxRepeating(str);
	return 0;
}

