#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    int maxH = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (v[i] > maxH) maxH = v[i];
    }

    int left = 0, right = maxH;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long wood = 0;

        for (int i = 0; i < N; i++) {
            if (v[i] > mid) {
                wood += v[i] - mid;
            }
        }

        if (wood >= M) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}