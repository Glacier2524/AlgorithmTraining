#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	
	if (b >= 0)
	{
		cout << (a + b) * n << endl;
	}
	else
	{
		
		int result = 0;
		for (int i = 1; i < n; i++)
		{

			if (s[i] != s[i - 1])
			{
				result++;
			}
		}
		
		int op = (result+1) / 2 + 1;
		cout << a * n + b * op << endl;
	}
}
int main()

{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}