#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find all lexicographic permutations of given
// string where repetition of characters is allowed
int n;
string str;
char path[10];

void rec(int pos)
{
	// base condition (permutation found)
	if (pos == n)
	{
		// print the permutation and return
		for(int i = 0; i < n; i++){
			cout << path[i];
		}
		cout << endl;
		return;
	}

	// consider all characters of the string one by one
	// for (unsigned i = 0; i < str.length(); i++)
	// {
	// 	// skip adjacent duplicates
	// 	while (i + 1 < str.length() && str[i] == str[i + 1])
	// 		i++;

	// 	lexicographic(str, res + str[i]);
	// }

	// above for loop can be replaced by below for loop

	 for (int i = pos; i < str.length(); i++){
		path[pos] = str[i];
		rec(pos + 1);
		path[pos] = '\0';		// backtrack
	}
}

int main()
{
	str = "123";
    n = str.size();
	string res;

	// sort the string to print in lexicographical order
	// sort(str.begin(), str.end());

	rec(0);

	return 0;
}