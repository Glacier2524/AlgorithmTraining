#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

void solve(int n)
{
	//store the data,string is citycode+state,int is the count of the pair
	map<string, int> m;
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		string city, state;
		cin >> city >> state;

		//get the first two characters
		string citycode = city.substr(0, 2);

		if (citycode != state)
		{
			//find the pair which I want in the map
			string wanna = state + citycode;
			result += m[wanna];

		}

		//record the count of the pair
		string pair = citycode + state;
		m[pair]++;
	}

	cout << result << endl;
}
int main()
{
	int n;
	cin >> n;
	solve(n);
	return 0;
}