#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using ll = long long;

int main() {
	ll n, cLen, g;
	cin >> n >> cLen >> g;
	
	vector<ll> minDist(cLen + 1, LLONG_MAX);
	vector<vector<pair<ll, ll>>> walkways(cLen + 1);
	
	for (ll i = 0; i < n; i++) {
		ll st, ed, time;
		cin >> st >> ed >> time;
		walkways[st].emplace_back(ed, time);
	}
	
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
	minDist[0] = 0;
	pq.emplace(0, 0);
	while (!pq.empty()) {
		auto [dst, x] = pq.top();
		pq.pop();
		if (dst != minDist[x])
			continue;
		
		auto walkTo = [&] (ll nx, ll cost) {
			ll nextCost = dst + cost;
			if (nx >= 0 && nx <= cLen && nextCost < minDist[nx]) {
				minDist[nx] = nextCost;
				pq.emplace(nextCost, nx);
			}
		};
		
		walkTo(x + 1, g);
		walkTo(x - 1, g);
		for (pair<ll, ll> w : walkways[x])
			walkTo(w.first, w.second);
	}
	
	cout << minDist[cLen] << "\n";
}
