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
	vector<pair<pii, int>> inp;
	for (int i = 0; i < n; ++i) {
		int x, y, a;
		cin >> x >> y >> a;
		--x; --y;
		inp.push_back({{y, x}, a});
	}
	sort(inp.begin(), inp.end());

	vector<vector<int>> field;

	int c = 0;
	int prev = 0;
	for (auto p : inp) {
		c += min(p.ff.ff - prev, h + 1);

		if (szof(field) <= c) {
			field.resize(c + 1, vector<int>(h, -INF));
		}

		field[c][p.ff.ss] = p.ss;

		prev = p.ff.ff;
	}

	ll ans = 0;

	for (int q = 0; q < 2; ++q) {
		auto mem = field;
		for (int i = szof(field) - 1; i >= 0; --i) {
			for (int j = szof(field[i]) - 1; j >= 0; --j) {
				if (field[i][j] == -INF) {
					if (((i + j) & 1) == q) {
						field[i][j] = min(i == szof(field) - 1 ? 0 : field[i + 1][j], j == szof(field[i]) - 1 ? 0 : field[i][j + 1]);
					} else {
						field[i][j] = max(i == szof(field) - 1 ? 0 : field[i + 1][j], j == szof(field[i]) - 1 ? 0 : field[i][j + 1]);
					}
				}
				if (((i + j) & 1) == q) {
					ans += field[i][j];
				}
			}
		}
		field = mem;
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
