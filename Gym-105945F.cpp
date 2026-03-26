#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<tuple>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int s;
    cin >> s;

    vector<int> wrongtime(n, 0);
    vector<bool> solved(n, false);
    vector<int> time(n, 0);
    vector<int> first_pd(n, -1);
    vector<tuple<int, string, string>> all_submits;

    for (int i = 0; i < s; i++)
    {
        int t;
        string prob, status;
        cin >> t >> prob >> status;
        all_submits.push_back({ t, prob, status });
        int id = prob[0] - 'A';
        if (status == "pd" && first_pd[id] == -1)
        {
            first_pd[id] = t;
        }
    }

    for (auto& sub : all_submits)
    {
        int t = get<0>(sub);
        string prob = get<1>(sub);
        string status = get<2>(sub);
        int id = prob[0] - 'A';

        if (t < 240)
        {
            if (status == "ac")
            {
                if (!solved[id])
                {
                    solved[id] = true;
                    time[id] = t;
                }
            }
            else if (status == "rj")
            {
                if (!solved[id])
                {
                    wrongtime[id]++;
                }
            }
        }
    }

    int solvedcount = 0;
    int penalty = 0;
    for (int i = 0; i < n; i++)
    {
        if (solved[i])
        {
            solvedcount++;
            penalty += time[i] + 20 * wrongtime[i];
        }
    }

    if (solvedcount > a || (solvedcount == a && penalty < b))
    {
        cout << 0 << endl;
        return;
    }

    vector<int> costs;
    for (int i = 0; i < n; i++)
    {
        if (!solved[i] && first_pd[i] != -1)
        {
            costs.push_back(first_pd[i] + 20 * wrongtime[i]);
        }
    }

    sort(costs.begin(), costs.end());

    int need = 0;
    int current_solved = solvedcount;
    int current_penalty = penalty;

    for (int cost : costs)
    {
        if (current_solved > a || (current_solved == a && current_penalty < b))
        {
            break;
        }
        current_solved++;
        current_penalty += cost;
        need++;
    }

    if (current_solved > a || (current_solved == a && current_penalty < b))
    {
        cout << need << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}