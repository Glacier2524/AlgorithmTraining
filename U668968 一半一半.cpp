#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

/*本题主要算法：二分*/
int main()
{
	//输入工作=======================
	long long n, k;
	cin >> n >> k;

	vector<int> S(n);
	vector<int> B(n);

	for (int i = 0; i < n; i++)
	{
		cin >> S[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	//==================================

	//通过题目给出上下界
	double high = 1e4, low = 0.0;

	for (int i = 0; i < 50; i++) //这里选择50次，因为2^50足以达到1e4
	{
		double mid = (high + low) / 2; //核心：二分
		vector<double>M(n);

		for (int j = 0; j < n; j++)
		{
			//核心思路，满足sum（S）/sum（B）>= mid，通过二分找到mid
			M[j] = S[j] - mid * B[j]; 
		}

		//nth—elemnet函数，将第k大的元素放到M【k-1】，并且保证前k-1个元素都大于第k个元素，后面都小于，而顺序不保证
		nth_element(M.begin(), M.begin() + k - 1, M.end(), greater<double>());

		double sum = 0.0;
		for (int j = 0; j < k; j++)
		{
			sum += M[j];
		}

		//二分，反复逼近
		if (sum >= 0)
			low = mid;
		else
			high = mid;
	}

	//fixed和setprecision函数保留小数点，包含头文件<iomanip>
	cout << fixed << setprecision(2) << low << endl;
	return 0;
}