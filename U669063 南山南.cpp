#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> v(105, vector<int>(105));
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void check(int x, int y, int n, int m)
{
    v[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == 1)
        {
            check(nx, ny, n, m);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            v[i][j] = s[j] - '0';
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                check(i, j, n, m);
                result++;
            }
        }
    }

    cout << result << endl;
    return 0;
}