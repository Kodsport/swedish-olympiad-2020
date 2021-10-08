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
    ll k,n;
    cin>>k>>n;
    vi v;
    ll ans = 0;
    ll tens = 0;
    rep(i,0,k){
        ll x;
        cin>>x;
        tens += x/10;
        v.push_back(x%10);
    }
    if(tens*10>=n){
        cout<<(n+9)/10<<endl;
        return 0;
    }
    n-=10*tens;
    ans+=tens;
    sort(all(v));
    while(n>0){
        ans++;
        n-=v.back();
        v.pop_back();
    }
    cout<<ans<<endl;
}
