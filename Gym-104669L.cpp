#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

using ll = long long;
bool check(ll L, ll R, ll f)
{
	if (L % f == 0) return true;
	ll first = ((L + f - 1) / f) * f;
	return first <= R;
}
void solve()
{
	long long a, b;
	cin >> a >> b;

	long long s = (2 * a +b-1) * b / 2;

	vector<ll>factors;
	for (ll i = 1; i * i <= s; i++)
	{
		if (s % i == 0)
		{
			factors.push_back(i);
			if (i != s / i)
			{
				factors.push_back(s / i);
			}
		}
		
	}

	reverse(factors.begin(), factors.end());

	ll result = 1;
	for (auto x : factors)
	{
		bool ok = false;
		for (ll i = 1; i <= b - 1; i++)
		{
			ll lefttemp = a * i + i * (i - 1) / 2;
			ll righttemp = i * a + i * (2 * b - i - 1) / 2;;

			if (check(lefttemp, righttemp, x))
			{
				ok = true;
				break;
			}
		}
		if (ok)
		{
			result = x;
			break;
		}

	}
	
	cout << result << endl;

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