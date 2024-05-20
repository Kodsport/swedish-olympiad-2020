#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
	out = res + 1;
	return res;
}

int main() {
	cin >> N >> K >> M;
	bad.assign(K + 1, vi(K + 1));
	rep(i,0,K) bad[i][i] = 1;
	rep(i,0,M) {
		string s;
		cin >> s;
		trav(x, s) trav(y, s) bad[x - 'A'][y - 'A'] = 1;
	}
	cout << rec(0, K) << endl;
}
