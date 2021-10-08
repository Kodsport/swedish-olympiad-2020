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

    //trav(intv,intvs){
    //    cout<<intv.first<<" "<<intv.second<<endl;
    //}

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
        //cout<<intvs[dn].first<<" "<<intvs[dn].second<<endl;
        //cout<<intvs[dn+1].first<<" "<<intvs[dn+1].second<<endl;

        ll score2 = min(intvs[dn+1].first-ql,qr-intvs[dn+1].second);
        ll score1 = min(intvs[dn].first-ql,qr-intvs[dn].second);
        ll win1 = ((qr-intvs[dn].second+intvs[dn].first-ql+1)%2+1);
        ll win2 = ((qr-intvs[dn+1].second+intvs[dn+1].first-ql+1)%2+1);

        bool valid1 = (intvs[dn].second<=qr&&intvs[dn].first>=ql);
        bool valid2 = (intvs[dn+1].second<=qr&&intvs[dn+1].first>=ql);

        //cout<<score1<<" "<<score2<<" "<<win1<<" "<<win2<<" "<<valid1<<" "<<valid2<<endl;

        if(!valid1&&!valid2) cout<<0<<endl;
        if(!valid1&&valid2) cout<<win2<<endl;
        if(valid1&&!valid2) cout<<win1<<endl;
        if(valid1&&valid2) {
            if(score1==score2&&(win1==1||win2==1)) cout<<1<<endl;
            else {
                if(score1>score2) cout<<win1<<endl;
                else cout<<win2<<endl;
            }
        }
    }

}
