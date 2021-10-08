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

    ll n,k,q;
    cin>>n>>k>>q;

    vi g(n);
    rep(i,0,n) cin>>g[i];

    vector<pii> intvs;

    ll numUnique = 0;
    vi numOfType(k);

    ll l = 0;
    ll r = 0;

    while(true){
        if(numUnique<k){
            if(r==n) break;
            numUnique += (numOfType[g[r]]==0);
            numOfType[g[r]]++;
            r++;
        } else {
            numOfType[g[l]]--;
            numUnique -= (numOfType[g[l]]==0);
            if(numUnique<k)
                intvs.emplace_back(l,r);
            l++;
        }
    }
    
    while(q--){
        ll ql,qr;
        cin>>ql>>qr;
        ql--;
        ll dn = 0;
        ll up = intvs.size();

        while(dn+1<up){
            ll mid = (dn+up)/2;
            if(intvs[mid].first-ql<qr-intvs[mid].second) dn = mid;
            else up = mid;
        }

        ll ans = 0;
        ll bestScore = -1e18;
        rep(i,max(0ll,dn-2),min(sz(intvs),dn+3)){
            ll score = min(intvs[i].first-ql,qr-intvs[i].second);
            ll win = ((qr-intvs[i].second+intvs[i].first-ql+1)%2+1);
            bool valid = (intvs[i].second<=qr&&intvs[i].first>=ql);

            if(valid&&(score>bestScore||(score==bestScore&&win==1))){
                ans = win;
                bestScore = score;
            }
        }
        cout<<ans<<endl;
    }

}
