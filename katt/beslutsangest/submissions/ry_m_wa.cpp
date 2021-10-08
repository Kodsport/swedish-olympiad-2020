#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const int M = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> xs, ys;
    vector<pair<pair<int, int>, int>> vals;

    for (int i = 0; i < k; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        x -= 1, y -= 1;
        vals.push_back({{x, y}, v});
        xs.push_back(x);
        xs.push_back(x + 1);
        ys.push_back(y);
        ys.push_back(y + 1);
    }

    xs.push_back(0), xs.push_back(n - 1);
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    ys.push_back(0), ys.push_back(m - 1);
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    vector<vector<pair<int, int>>> dp(xs.size(), vector<pair<int, int>>(ys.size()));
    vector<vector<bool>> has(xs.size(), vector<bool>(ys.size()));
    vector<vector<int>> a(xs.size(), vector<int>(ys.size()));

    for (const auto& it : vals) {
        int x = lower_bound(xs.begin(), xs.end(), it.first.first) - xs.begin();
        int y = lower_bound(ys.begin(), ys.end(), it.first.second) - ys.begin();
        has[x][y] = 1;
        a[x][y] = it.second;
    }

    long long res = 0;
    for (int i = xs.size() - 1; i >= 0; --i) {
        for (int j = ys.size() - 1; j >= 0; --j) {
            if (has[i][j]) {
                dp[i][j] = {a[i][j], a[i][j]};
            } else {
                dp[i][j] = {
                    min(i + 1 < xs.size() ? dp[i+1][j].second : 0, j + 1 < ys.size() ? dp[i][j+1].second : 0),
                    max(i + 1 < xs.size() ? dp[i+1][j].first : 0, j + 1 < ys.size() ? dp[i][j+1].first : 0)
                };
            }
            long long w = (i + 1 < xs.size() ? xs[i + 1] : n) - xs[i];
            long long h = (j + 1 < ys.size() ? ys[i + 1] : m) - ys[i];
            res += w * h % M * dp[i][j].first % M;
        }
    }

    cout << (res % M + M) % M << '\n';

    return 0;
}
