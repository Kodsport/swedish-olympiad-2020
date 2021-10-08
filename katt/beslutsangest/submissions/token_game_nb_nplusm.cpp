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
	int m = max(h, w);
	vector<set<pii>> intr_cells(2);
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
					}
				}
			}
		}
	}

	int ans = 0;
	vector<pii> change;
	for (int q = 0; q < 2; ++q) {
		vector<pii> cur_intr_cells(intr_cells[q].begin(), intr_cells[q].end());
		sort(cur_intr_cells.begin(), cur_intr_cells.end(), [&](pii p1, pii p2) {
			return p1.ff - p1.ss < p2.ff - p2.ss || (p1.ff - p1.ss == p2.ff - p2.ss && p1.ff + p1.ss < p2.ff + p2.ss);
		});

		auto it = cur_intr_cells.begin();
		ll sum = 0;
		vector<int> arr(m * 2);
		for (int i = -m + 1; i < m; ++i) {
			if ((i & 1) != q) {
				continue;
			}

			int l = abs(i);
			int r = m * 2 - 2 - abs(i);

			if (i <= 0) {
				sum += arr[l];
				if (l != r)	{
					sum += arr[r];
				}
			} else if (i > 1) {
				sum -= arr[l - 2];
				sum -= arr[r + 2];
			}

			change.clear();

			while (it != cur_intr_cells.end() && it->ff - it->ss == i) {
				int x, y;
				tie(x, y) = *it;
				
				if (inp.count({x, y})) {
					//arr[x + y] = inp[{x, y}];
					change.push_back({x + y, inp[{x, y}]});
				} else {
					int val1;
					if (x == 0) {
						val1 = 0;
					} else if (inp.count({x - 1, y})) {
						val1 = inp[{x - 1, y}];
					} else {
						val1 = max(arr[x + y], x + y - 2 >= 0 ? arr[x + y - 2] : 0);
					}
					int val2;
					if (y == m - 1) {
						val2 = 0;
					} else if (inp.count({x, y + 1})) {
						val2 = inp[{x, y + 1}];
					} else {
						val2 = max(arr[x + y], x + y + 2 < szof(arr) ? arr[x + y + 2] : 0);
					}

					// arr[x + y] = min(val1, val2);
					change.push_back({x + y, min(val1, val2)});
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


			ans = (ans + sum) % MOD;
			// cerr << sum << endl;
			// for (int j = l; j <= r; j += 2) {
			// 	cerr << arr[j] << " ";
			// }
			// cerr << endl;
		}
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
