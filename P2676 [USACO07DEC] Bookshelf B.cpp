#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n,b;
	cin >> n >> b;

	vector<int> cow(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cow[i];
	}

	sort(cow.begin(), cow.end(),greater<int>());
	int sum = 0;      
	int count = 0;    

	
	for (int i = 0; i < n && sum < b; i++)
	{
		sum += cow[i];
		count++;
	}
	cout << count << endl;
	return 0;
}