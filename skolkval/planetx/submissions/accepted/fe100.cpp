#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define trav(a,c) for(auto a: c)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
    cin.sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<vi> mn(n,vi(m,0));
    vector<vi> mx(n,vi(m,9));

    rep(i,0,n) rep(j,0,m){
        char c; cin>>c;
        if(c=='.') continue;
        ll x = c-'0';

        rep(i2,0,n) rep(j2,0,m){
            ll dst = abs(i-i2)+abs(j-j2);
            mn[i2][j2] = max(mn[i2][j2],x-dst);
            mx[i2][j2] = min(mx[i2][j2],x+dst);
        }
    }
    
    rep(i,0,n) {
        rep(j,0,m){
            if(mn[i][j]==mx[i][j]) cout<<mn[i][j];
            else cout<<'.';
        }
        cout<<endl;
    }
}
