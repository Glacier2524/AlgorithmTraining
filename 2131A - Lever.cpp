#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

void solve()
{
	int len;
	cin >> len;

	vector<int>a(len), b(len);
	for (int i = 0; i < len; i++)
	{
		cin >> a[i];

	}
	for (int i = 0; i < len; i++)
	{
		cin >> b[i];

	}
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] > b[i])
			sum += a[i] - b[i];
	}
	cout << sum+1 << endl;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		solve();
	}
	return 0;
}