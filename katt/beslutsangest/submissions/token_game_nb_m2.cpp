// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 998244353;

void solve() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<vector<int>> field(h, vector<int>(w, INF));

	for (int i = 0; i < n; ++i) {
		int x, y, a;
		cin >> x >> y >> a;
		--x; --y;
		field[x][y] = a;
	}

	ll ans = 0;

	for (int q = 0; q < 2; ++q) {
		vector<vector<int>> res(h, vector<int>(w));
		for (int i = h - 1; i >= 0; --i) {
			for (int j = w - 1; j >= 0; --j) {
				if (field[i][j] != INF) {
					res[i][j] = field[i][j];
				} else {
					if (((i + j) & 1) == q) {
						res[i][j] = min(i + 1 < h ? res[i + 1][j] : 0, j + 1 < w ? res[i][j + 1] : 0);
					} else {
						res[i][j] = max(i + 1 < h ? res[i + 1][j] : 0, j + 1 < w ? res[i][j + 1] : 0);
					}
				}

				if (((i + j) & 1) == q) {
					ans += res[i][j];
				}
			}
		}
	}

	cout << (ans % MOD + MOD) % MOD << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
