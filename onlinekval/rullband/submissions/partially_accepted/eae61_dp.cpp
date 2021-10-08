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

ll memo[200005];
ll dp(ll i) {
	if (i >= walkways.size() - 1)
		return 0;
	if (memo[i] != -1)
		return memo[i];
	
	ll nextAfter = lower_bound(walkways.begin() + i + 1, walkways.end(), walkways[i].end) - walkways.begin();
	return memo[i] = min(
		dp(nextAfter) + walkways[i].time + g * (walkways[nextAfter].start - walkways[i].end),
		dp(i + 1) + g * (walkways[i + 1].start - walkways[i].start)
	);
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
	
	fill(all(memo), -1);
	cout << dp(0) << "\n";
}
