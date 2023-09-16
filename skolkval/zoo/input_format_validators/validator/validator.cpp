#include "validator.h"

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM = 2'000'000'000;

int N, K, M;
vector<vi> bad;
map<pii, ll> mem;
ll rec(int at, int prev) {
	if (at == N) return 1;
	ll& out = mem[pii(at, prev)];
	if (out) return out - 1;
	ll res = 0;
	rep(i,0,K) if (!bad[prev][i])
		res += rec(at + 1, i);
	assert(res <= LIM);
	out = res + 1;
	return res;
}

void run() {
	N = Int(2, Arg("maxn", 15));
	Space();
	K = Int(2, Arg("maxk", 10));
	Space();
	M = Int(0, Arg("maxm", 5));
	Endl();

	bad.assign(K + 1, vi(K + 1));
	rep(i,0,K) bad[i][i] = 1;

	rep(i,0,M) {
		string s = _token();
		Endl();
		assert(s.size() >= 2 && s.size() <= K);
		trav(x, s) {
			assert('A' <= x && x < (char)('A' + K));
		}
		assert(set<char>(s.begin(), s.end()).size() == s.size());
		trav(x, s) trav(y, s) bad[x - 'A'][y - 'A'] = 1;
	}
	rec(0, K);
}
