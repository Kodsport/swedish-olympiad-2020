#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector< vector<ll> > vii;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(a) a.begin(),a.end()
#define sz(a) (ll) (a).size()
#define pb push_back
const ll inf = 90000000000;
const ll mod = 1000000009;
ll max(ll a, ll b){if(a>b) return a; else return b;}

int main(){
    ll n; cin >> n;
    vii tree;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    vi steps, bt;
    rep(i,0,n){
        ll m; cin >> m;
        vi neigh;
        rep(j,0,m){
            ll neigh_j; cin >> neigh_j; neigh.pb(neigh_j);
        }
        if (m == 1) q.push({0,i});
        bt.pb(m); steps.pb(0); tree.pb(neigh);
    }
    ll last = 0;
    while(q.empty() == 0){
        ll node = q.top().second; q.pop();
        last = node;
        rep(i,0,tree[node].size()){
            bt[tree[node][i]] --;
            if(steps[tree[node][i]] < steps[node] + 1) steps[tree[node][i]] = steps[node] + 1;
            else steps[tree[node][i]]++;
            if(bt[tree[node][i]] == 1) q.push({steps[tree[node][i]], tree[node][i]});
        }
    }
    cout << steps[last] << endl;
}
