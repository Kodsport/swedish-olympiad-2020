#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	const int lim = 300;
	int N, Q;
	cin >> N >> Q;
	vector<int> sieve(N+1);
	vector<vi> forb(lim, vi(lim));
	auto blocked = [&](int a) -> bool {
		if (sieve[a]) return true;
		rep(b,1,lim) {
			if (forb[b][a % b]) return true;
		}
		return false;
	};
	rep(i,0,Q) {
		int t, a, b;
		cin >> t >> a;
		if (t == 1) {
			cout << (blocked(a) ? "ja" : "nej") << '\n';
		} else {
			cin >> b;
			int mult = (t == 2 ? 1 : -1);
			if (b < lim) {
				forb[b][a] += mult;
			}
			else {
				for (int i = a; i <= N; i += b) sieve[i] += mult;
			}
		}
	}
}
