#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")

using namespace std;

#define rep(i, a, b) for(ll i = a; i < ll(b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    ll n,m,g;
    cin>>n>>m>>g;

    vector<vector<pii>> e(m);

    rep(i,0,n){
        ll a,b,c;
        cin>>a>>b>>c;
        e[b-1].emplace_back(a-1,c);
    }

    vi dp(m,1e18);
    dp[0] = 0;
    rep(i,1,m) {
        dp[i] = dp[i-1]+g;
        //cout<<dp[i]<<endl;
        trav(ed,e[i]) dp[i] = min(dp[i],dp[ed.first]+ed.second);
        //cout<<dp[i]<<endl;
    }
    cout<<dp[m-1]+g<<endl;
}