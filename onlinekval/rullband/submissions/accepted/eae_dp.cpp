#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using ll = long long;

struct Walkway {
	ll start, end, time;
	bool operator<(const Walkway& x) { return start < x.start; }
	bool operator<(ll x) { return start < x; }
};
vector<Walkway> walkways;
ll g;

struct SegTree {
	vector<ll> s; ll n;
	SegTree(ll len) : s(2 * len, LLONG_MAX), n(len) {}
	void set(ll pos, ll val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = min(s[pos * 2], s[pos * 2 + 1]);
	}
	ll query(ll lo, ll hi) {
		ll ra = LLONG_MAX, rb = LLONG_MAX;
		for (lo += n, hi += n; lo < hi; lo /= 2, hi /= 2) {
			if (lo % 2) ra = min(ra, s[lo++]);
			if (hi % 2) rb = min(s[--hi], rb);
		}
		return min(ra, rb);
	}
};

ll dp[200005][2];

int main() {
	ll n, cLen;
	cin >> n >> cLen >> g;
	
	walkways.resize(n);
	for (ll i = 0; i < n; i++) {
		cin >> walkways[i].start >> walkways[i].end >> walkways[i].time;
	}
	walkways.push_back({ 0, 0, 0 });
	walkways.push_back({ cLen, cLen, 0 });
	sort(all(walkways));
	
	SegTree segTree(walkways.size());
	segTree.set(walkways.size() - 1, -g * walkways.back().start);
	
	for (ll i = walkways.size() - 2; i >= 0; i--) {
		ll iLo = lower_bound(walkways.begin(), walkways.end(), walkways[i].start + 1) - walkways.begin();
		ll iHi = lower_bound(walkways.begin() + iLo, walkways.end(), walkways[i].end) - walkways.begin();
		dp[i][1] = dp[iHi][0] + g * abs(walkways[iHi].start - walkways[i].end);
		if (iHi > iLo) {
			dp[i][1] = min(dp[i][1], segTree.query(iLo, iHi) + g * walkways[i].end);
		}
		dp[i][0] = min(dp[i + 1][0] + g * (walkways[i + 1].start - walkways[i].start), dp[i][1] + walkways[i].time);
		segTree.set(i, dp[i][false] - g * walkways[i].start);
	}
	
	cout << dp[0][true] << "\n";
}
