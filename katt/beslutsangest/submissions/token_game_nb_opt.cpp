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

struct cells_order {
	bool operator()(pii p1, pii p2) {
		return p1.ff - p1.ss < p2.ff - p2.ss || (p1.ff - p1.ss == p2.ff - p2.ss && p1.ff + p1.ss < p2.ff + p2.ss);
	}
};

void solve() {
	int h, w, n;
	cin >> h >> w >> n;
	int m = max(h, w);
	vector<set<pii, cells_order>> intr_cells(2);
	vector<set<int>> intr_diags(2);
	map<pii, int> inp;
	for (int i = 0; i < n; ++i) {
		int x, y, v;
		cin >> x >> y >> v;
		--y;
		x = m - x;
		inp[{x, y}] = v;
		for (int dx = 0; dx <= 2; ++dx) {
			for (int dy = -2; dy <= 0; ++dy) {
				if (abs(dx) + abs(dy) <= 2) {
					int nx = x + dx;
					int ny = y + dy;
					if (0 <= nx && nx < m && 0 <= ny && ny < m) {
						intr_cells[(nx + ny) & 1].insert({nx, ny});
						intr_diags[(nx + ny) & 1].insert(nx - ny);
					}
				}
			}
		}
	}

	int ans = 0;
	vector<pii> change;
	for (int q = 0; q < 2; ++q) {
		auto it = intr_cells[q].begin();
		auto it_diag = intr_diags[q].begin();
		ll sum = 0;
		unordered_map<int, int> arr;
		int prev = -INF;
		while (it_diag != intr_diags[q].end()) {
			int i = *it_diag;
			ans = (ans + (ll) (i - prev) / 2 * (sum % MOD)) % MOD;
			int l = abs(i);
			int r = m * 2 - 2 - abs(i);

			if (i > 1) {
				if (arr.count(l - 2)) {
					sum -= arr[l - 2];
				}
				if (arr.count(r + 2)) {
					sum -= arr[r + 2];
				}
			}

			change.clear();

			while (it != intr_cells[q].end() && it->ff - it->ss == i) {
				int x, y;
				tie(x, y) = *it;

				if (inp.count({x, y})) {
					change.push_back({x + y, inp[{x, y}]});
				} else {
					int val1;
					if (inp.count({x - 1, y})) {
						val1 = inp[{x - 1, y}];
					} else {
						val1 = max(arr.count(x + y) ? arr[x + y] : 0, arr.count(x + y - 2) ? arr[x + y - 2] : 0);
					}
					int val2;
					if (inp.count({x, y + 1})) {
						val2 = inp[{x, y + 1}];
					} else {
						val2 = max(arr.count(x + y) ? arr[x + y] : 0, arr.count(x + y + 2) ? arr[x + y + 2] : 0);
					}

					change.push_back({x + y, min(val1, val2)});
					if (x + y < m - 2) {
						intr_diags[q].insert(x + y + 2);
					} else if (x + y >= m + 1) {
						intr_diags[q].insert(m - 1 - (x + y - (m - 1) - 2));
					}
				}

				++it;
			}

			for (pii p : change) {
				if (l <= p.ff && p.ff <= r) {
					sum -= arr[p.ff];
				}

				arr[p.ff] = p.ss;

				if (l <= p.ff && p.ff <= r) {
					sum += arr[p.ff];
				}
			}


			prev = i;
			++it_diag;
		}

		ans = (ans + (ll) (((m & 1) == q ? m : m + 1) - prev) / 2 * (sum % MOD)) % MOD;
	}

	cout << (ans + MOD) % MOD << "\n";
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
