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
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef gp_hash_table<int, int> table;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 998244353;

const int MAX_N = 1000 * 1000 + 228;

struct point {
    int x;
    int y;
};

bool operator<(const point& a, const point& b) {
    return a.x + a.y > b.x + b.y || (a.x + a.y == b.x + b.y && a.x - a.y < b.x - b.y);
}

bool operator==(const point& a, const point& b) {
    return a.x == b.x && a.y == b.y;
}

ll n, m;
int k;
map<pair<int, int>, int> costs;
vector<point> points[2];
vector<int> diags[2];
table dp;

inline int calc_cost(int x, int ptr1, int ptr2, map<pair<int, int>, int>::iterator it) {
    if (x == n - 1) {
        return 0;
    } else if (it != costs.end()) {
        return it->second;
    } else {
        int ans = -INF;
        auto it_ptr1 = dp.find(ptr1);
        auto it_ptr2 = dp.find(ptr2);

        if (1 <= ptr1 && ptr1 <= n + n - 1 && it_ptr1 != dp.end()) {
            ans = max(ans, dp[ptr1]);
        } else {
            ans = max(ans, 0);
        }
        if (1 <= ptr2 && ptr2 <= n + n - 1 && it_ptr2 != dp.end()) {
            ans = max(ans, dp[ptr2]);
        } else {
            ans = max(ans, 0);
        }

        return ans;
    }
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%lld%lld%d", &n, &m, &k);
    n = max(n, m); // magic

    for (int i = -1; i <= k; ++i) {
        int x, y, c;
        if (i == -1) {
            x = 1;
            y = 0;
            c = 0;
        } else if (i == 0) {
            x = 0;
            y = 0;
            c = 0;
        } else {
            scanf("%d%d%d", &x, &y, &c);
            --x; --y;
            costs[{x, y}] = c;
        }
        for (int dx = 0; dx <= 2; ++dx) {
            for (int dy = 0; dy <= 2; ++dy) {
                int gox = x - dx;
                int goy = y - dy;
                if (gox >= 0 && goy >= 0 && dx + dy <= 2) {
                    points[(gox + goy) & 1].push_back({gox, goy});
                    diags[(gox + goy) & 1].push_back(gox + goy);

                    if (gox - goy >= 0) {
                        points[(gox + goy) & 1].push_back({gox - goy, 0});
                        diags[(gox + goy) & 1].push_back({gox - goy});
                    } else {
                        points[(gox + goy) & 1].push_back({0, goy - gox});
                        diags[(gox + goy) & 1].push_back(goy - gox);
                    }

                    if (gox - goy >= 2) {
                        points[(gox + goy) & 1].push_back({gox - goy - 2, 0});
                        diags[(gox + goy) & 1].push_back({gox - goy - 2});
                    } else if (gox - goy <= -2) {
                        points[(gox + goy) & 1].push_back({0, goy - gox + 2});
                        diags[(gox + goy) & 1].push_back(goy - gox + 2);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        dp.clear();
        sort(points[i].begin(), points[i].end());
        points[i].resize(unique(points[i].begin(), points[i].end()) - points[i].begin());
        sort(diags[i].begin(), diags[i].end());
        diags[i].resize(unique(diags[i].begin(), diags[i].end()) - diags[i].begin());
        reverse(diags[i].begin(), diags[i].end());

        int cur_add = 0;
        int points_ptr = 0;
        for (int j = 0; j < (int)diags[i].size(); ++j) {
            int lf = 0;
            int rf = 0;

            if (diags[i][j] >= n - 1) {
                lf = n - ((n + n - 2) - diags[i][j]);
                rf = n + ((n + n - 2) - diags[i][j]);
            } else {
                lf = n - diags[i][j];
                rf = n + diags[i][j];
            }

            if (j != 0) {
                ans = (ans + (ll)(diags[i][j - 1] - diags[i][j] - 1) / 2ll * cur_add) % MOD;
            }

            if (diags[i][j] < n - 1) {
                if (dp.find(lf - 2) != dp.end()) {
                    cur_add = (cur_add - dp[lf - 2]) % MOD;
                }
                if (dp.find(rf + 2) != dp.end()) {
                    cur_add = (cur_add - dp[rf + 2]) % MOD;
                }
            }

            vector<pair<int, int>> new_vals;
            for ( ;
                points_ptr < (int)points[i].size() && points[i][points_ptr].x + points[i][points_ptr].y >= diags[i][j];
                ++points_ptr) {

                int x = points[i][points_ptr].x;
                int y = points[i][points_ptr].y;

                auto it = costs.find({x, y});
                int rl_val = min(
                    it != costs.end() ? it->second : calc_cost(x, n + x - y + 2, n + x - y, costs.find({x + 1, y})),
                    it != costs.end() ? it->second : calc_cost(y, n + x - y - 2, n + x - y, costs.find({x, y + 1}))
                );

                if (lf <= n + x - y && n + x - y <= rf) {
                    new_vals.push_back({n + x - y, rl_val});
                }
            }

            for (int i = 0; i < (int)new_vals.size(); ++i) {
                cur_add = (cur_add - dp[new_vals[i].first]) % MOD;
                cur_add = (cur_add + new_vals[i].second) % MOD;
                dp[new_vals[i].first] = new_vals[i].second;
            }

            /*
            cerr << "Now " << diags[i][j] << endl;
            for (int i = lf; i <= rf; i += 2) {
                cerr << dp[i] << " ";
            }
            cerr << endl;
            */

            ans = (ans + cur_add) % MOD;
        }
    }

    if (ans < 0) {
        ans += MOD;
    }

    printf("%d\n", ans);

    return 0;
}


