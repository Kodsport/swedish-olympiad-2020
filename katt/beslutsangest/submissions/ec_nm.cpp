#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 998244353;

const int MAX_N = 1005;

inline void add(int& x, int y) {
    x += y;
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
}

int n, m, k;
int arr[MAX_N][MAX_N][2];

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j][0] = INF;
            arr[i][j][1] = INF;
        }
    }

    for (int i = 0; i < k; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        --x; --y;
        arr[x][y][0] = c;
        arr[x][y][1] = c;
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (arr[i][j][0] == INF) {
                arr[i][j][0] = min(arr[i + 1][j][1], arr[i][j + 1][1]);
                arr[i][j][1] = max(arr[i + 1][j][0], arr[i][j + 1][0]);
            }
            add(ans, arr[i][j][0] % MOD);
        }
    }

    printf("%d\n", ans);

    return 0;
}

