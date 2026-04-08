#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*学习新算法：01背包问题及简单dp*/

int time(vector<int>& test, int testtime)
{
	int sum = 0;
	for (int j = 0; j < testtime; j++)
	{
		cin >> test[j];
		sum += test[j];
	}

	//本题思路就是将一堆时间不同的题分成两堆，且两堆总和之差越小越好
	int target = sum / 2; //这里target就是最完美的情况，恰好分作两堆

	//01背包的核心代码，dp[i]表示是否可以凑出长度为i的堆
	//由于分堆的对称性，大小比target多1即可，dp【target】即最完美
	vector<bool>dp(target + 1, false); 

	//无论什么情况都能凑出时间为0的堆！
	dp[0] = true;

	for (int j = 0; j < testtime; j++)
	{
		for (int i = target; i >= test[j]; i--)
		{
			if (dp[i - test[j]])
			{
				dp[i] = true; //这里其实运用了一点递归，i=test【j】的情况一定true
			}
		}
	}

	int best = 0;
	for (int i = target;i>=0;i--)
	{
		if (dp[i])
		{
			best = i; //即使未达到target，选择离target最近的
			break;
		}
			
	}
	int result = max(sum - best, best);
	return result;
}
	
int main()
{
	int s[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> s[i];
	}
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		vector<int>test(s[i]);
		result += time(test, s[i]);
	}
	cout << result << endl;
	
	return 0;
}