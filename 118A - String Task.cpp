#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;

	transform(s.begin(), s.end(), s.begin(), ::tolower); //converting string to lowercase
	string result;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'y' || s[i] == 'e' || s[i] == 'u' || s[i] == 'i')
			continue;
		else
		{
			result += '.';
			result += s[i];
		}
	}
	cout << result << endl;
}