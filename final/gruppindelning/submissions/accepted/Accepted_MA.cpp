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

vi ans, m_lista, checklista;
int n,m;

void fill(int i, int val, int lst){
    checklista[i] += 1;
    if (ans[i] && (ans[i] != val && val != -1)) {cout << -1 << endl; exit(0);}
    if (ans[i]) return;
    if (val == -1) val = 1;
    ans[i] = val;

    int nxt_to;
    if (i % 2 == 0) nxt_to = i + 1;
    else nxt_to = i - 1;

    if (nxt_to != lst && nxt_to < n && checklista[nxt_to] < 2) fill(nxt_to, val % 2 + 1, i);

    if (m_lista[i] != -1 && m_lista[i] != lst && checklista[m_lista[i]] < 2) fill(m_lista[i], val, i);
    return;
}

int main(){
    cin >> n >> m;
    rep(i,0,n) m_lista.pb(-1);
    rep(i,0,m){
        int a,b; cin >> a >> b;
        m_lista[a-1] = b-1;
        m_lista[b-1] = a-1; 
    }
    rep(i,0,n) {ans.pb(0); checklista.pb(0);}

    int check = 1;
    for(int i = 0; i < n; i += 2){
        fill(i,-1,-1);
    }

    rep(i,0,n) cout << ans[i];
    cout << endl;
}
