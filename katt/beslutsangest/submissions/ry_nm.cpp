#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int n, m, k;
const int N = 1001, M = 998244353;
bool has[N][N];
int a[N][N];
int d[N][N][2];

long long naive() {
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (has[i][j]) {
                d[i][j][0] = d[i][j][1] = a[i][j];
            } else {
                d[i][j][0] = min(i < n - 1 ? d[i+1][j][1] : 0, j < m - 1 ? d[i][j+1][1] : 0);
                d[i][j][1] = max(i < n - 1 ? d[i+1][j][0] : 0, j < m - 1 ? d[i][j+1][0] : 0);
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res += d[i][j][0];
        }
    }
    return (res % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        has[x][y] = true;
        cin >> a[x][y];
    }

    cout << naive() << '\n';

    return 0;
}
