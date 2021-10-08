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

ll memo[200005][2];
ll dp(ll i, bool ed) {
	if (i >= walkways.size() - 1)
		return 0;
	if (memo[i][ed] != -1)
		return memo[i][ed];
	
	ll pos = ed ? walkways[i].end : walkways[i].start;
	ll ans = LLONG_MAX;
	
	if (ed) {
		ll iLo = lower_bound(walkways.begin(), walkways.end(), walkways[i].start + 1) - walkways.begin();
		ll iHi = lower_bound(walkways.begin() + iLo, walkways.end(), pos) - walkways.begin();
		
		for (ll j = iLo; j <= iHi; j++) {
			ans = min(ans, dp(j, false) + g * abs(walkways[j].start - pos));
		}
	} else {
		ans = min(dp(i + 1, false) + g * (walkways[i + 1].start - pos), dp(i, true) + walkways[i].time);
	}
	
	return memo[i][ed] = ans;
}

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
	
	fill_n(memo[0], sizeof(memo) / sizeof(ll), -1);
	cout << dp(0, true) << "\n";
}
