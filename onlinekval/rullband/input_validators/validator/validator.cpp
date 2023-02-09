#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < ll(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAX_TIME = 100;

ll n,m,g;
vector<vector<pii>> e;


ll solveDP(){
	vi dp(m,1e18);
    dp[m-1] = 0;
	for(ll i = m-2;i>=0;i--) {
        dp[i] = dp[i+1]+g;
        trav(ed,e[i]) dp[i] = min(dp[i],dp[ed.first]+ed.second);
    }
    return dp[0]+g;
}

ll solve(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.emplace(0,0);

    vector<bool> seen(m);

    while(pq.size()){
        ll d,v;
        tie(d,v) = pq.top();
        pq.pop();
        if(v<0||v>=m||seen[v]) continue;
        seen[v] = true;
        if(v==m-1){
            return d+g;
        }
        pq.emplace(d+g,v+1);
        pq.emplace(d+g,v-1);

        trav(ed,e[v]){
            pq.emplace(ed.second+d,ed.first);
        }
    }
    assert(false);
	return 0;
}

void run() {
	n = Int(1,Arg("nMax"));
	Space();
	m = Int(1, Arg("mMax"));
    Space();
	g = Int(1, MAX_TIME);
	Endl();

	e.resize(m);
	rep(i,0,n){
		ll a,b,t;
		a = Int(1,m);
    	Space();
		b = Int(a+1,m);
    	Space();
		t = Int(1,MAX_TIME);
		Endl();
		e[a-1].emplace_back(b-1,t);
	}


	if(int(Arg("onlyForward"))==1){
		assert(solveDP()==solve());
	}
}
