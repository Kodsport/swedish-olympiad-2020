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

ll n,m;
vector<vi> g;

bool inside(ll r,ll c){
    return (r>=0&&c>=0&&r<n&&c<m);
}

ll maxDistSameLevel(ll r,ll c,ll tr,ll tc, vector<vector<bool>> &seen){
    if(g[r][c]!=g[tr][tc]) return -1000;
    if(seen[r][c]) return -1000;
    if(r==tr&&c==tc) return 0;
    seen[r][c] = true;
    
    ll ans = -1000;
    rep(dr,-1,2) rep(dc,-1,2){
        if(dr==0&&dc==0) continue;
        if(!inside(r+dr,c+dc)) continue;
        ans = max(maxDistSameLevel(r+dr,c+dc,tr,tc,seen)+ 1,ans);
    }
    
    seen[r][c] = false;
    return ans;
}

ll dp(ll r,ll c){
    ll ans = 0;
    rep(i,0,n) rep(j,0,m){
        vector<vector<bool>> seen(n,vector<bool>(m));
        ll d = maxDistSameLevel(r,c,i,j,seen);
        ans = max(d,ans);
        rep(dr,-1,2) rep(dc,-1,2){
            if(!inside(i+dr,j+dc)) continue;
            if(g[i+dr][j+dc]<g[r][c])
                ans = max(ans,d+1+dp(i+dr,j+dc));
        }
    }
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    cin>>n>>m;
    g.resize(n,vi(m));

    rep(i,0,n) rep(j,0,m){
        char c;
        cin>>c;
        g[i][j] = c-'0';
    }

    ll ans = 0;

    rep(i,0,n) {
        rep(j,0,m) ans = max(ans,dp(i,j));
    }
    cout<<ans+1<<endl;
}