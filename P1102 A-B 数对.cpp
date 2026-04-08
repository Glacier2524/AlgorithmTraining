#include<iostream>
#include<vector>
#include<algorithm>
using i64 = long long;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 N, C;
	cin >> N >> C;

	vector<i64>v(N);
	for (i64 i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	i64 sum = 0;
	i64 j = 0, k = 0;
	for (i64 i = 0; i < N; i++)
	{
		i64 target = v[i] + C;
		while (j < N && v[j] < target)
		{
			j++;
		}
		while (k < N && v[k] <= target)
		{
			k++;
		}

		sum += k - j;
	}

	cout << sum << endl;

}