#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, m, a;
	cin >> n >> m >> a;

	long long nt = (n + a - 1) / a;
	long long mt = (m + a - 1) / a;

	cout << mt * nt << endl;
	return 0;

}