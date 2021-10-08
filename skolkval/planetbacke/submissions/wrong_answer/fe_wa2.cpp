/*
går till godtycklig av 
de lediga rutorna som är på samma höjd
eller lägre och så höga som möjligt.
 */


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

ll getLongest(ll r,ll c){
    ll ans = 0;
    vector<vector<bool>> seen(n,vector<bool>(m));
    while(inside(r,c)){
        seen[r][c] = true;
        pair<ll,pii> bestNext = {0,{-1,-1}};

        rep(dr,-1,2) rep(dc,-1,2){
            if(!inside(r+dr,c+dc)||seen[r+dr][c+dc]) continue;
            if(g[r+dr][c+dc]<=g[r][c])
                bestNext = max(bestNext,{g[r+dr][c+dc],{r+dr,c+dc}});
        }
        ans++;
        r = bestNext.second.first;
        c = bestNext.second.second;

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
        rep(j,0,m) {
            //cout<<getLongest(i,j)<<" ";
            ans = max(ans,getLongest(i,j));
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
}