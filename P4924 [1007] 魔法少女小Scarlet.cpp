#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> magic(505, vector<int>(505, 0));
void scarlet(int x, int y, int r, int z, vector<vector<int>>& v)
{
	int x1 = x - r;
	int x2 = x + r;
	int y1 = y - r;
	int y2 = y + r;

	if (z == 0)
	{
		for (int i = 0; i < r; i++) //rotate circle by circle
		{
			int len = 2 * (r - i);
			for (int j = 0; j < len; j++)
			{
				int t = v[x1 + i + j][y2 - i]; // store the up line
				v[x1 + i + j][y2 - i] = v[x1 + i][y1 + i + j]; // left->up
				v[x1 + i][y1 + i + j] = v[x2 - i - j][y1 + i]; //down->left
				v[x2 - i - j][y1 + i] = v[x2 - i][y2 - i - j]; //right->down
				v[x2 - i][y2 - i - j] = t;//up->right
			}
		}
	}
	else
	{
		for (int i = 0; i < r; i++)
		{
			int len = 2 * (r - i);
			for (int j = 0; j < len; j++)
			{
				int t = v[x1 + i + j][y2 - i]; // store the up line
				v[x1 + i + j][y2 - i] = v[x2 - i][y2 - i - j]; // right->up
				v[x2 - i][y2 - i - j] = v[x2 - i - j][y1 + i];//down->right
				v[x2 - i - j][y1 + i] = v[x1 + i][y1 + i + j]; //left->down
				v[x1 + i][y1 + i + j] = t;//up->left
			}
		}
	}


}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			magic[i][j] = i * n + j + 1;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, r, z;
		cin >> x >> y >> r >> z;
		scarlet(x - 1, y - 1, r, z, magic);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << magic[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}